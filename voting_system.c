#include <stdio.h>
#include <string.h>

#define MAX_C 10 // Skibidi Rizz  Max 10 jon prathi thakte parbe 

// Prathider jonno ekta structure banano holo 
typedef struct Candidate {
    char name[50]; // Prothir naam 
    int votes; // Prothir vote songkha 
} Candidate;

Candidate allCandidates[MAX_C]; // 10 jon prathir data rakhte ekta array 
int candidateCount = 0; // Total prathi count

// Prathir naam input nibar function 
void fillCandidate(int cNum) {
    printf("Prathi %d er naam likhun (Rizz Up!): ", cNum + 1);
    fgets(allCandidates[cNum].name, 50, stdin);
    allCandidates[cNum].name[strcspn(allCandidates[cNum].name, "\n")] = 0; // Newline character remove kora 
    allCandidates[cNum].votes = 0;
}

// Sob prathir talika dekhanor function 
void displayAllCandidates() {
    printf("\nPrathider Talika (Vote Wisely):\n");
    for (int j = 0; j < candidateCount; j++) {
        printf("%d. %s\n", j + 1, allCandidates[j].name);
    }
}

// Vote nibar function 
void getVotes(int voterCount) {
    int choice;
    displayAllCandidates();
    printf("Voter %d, apnar poshondo likhun (1-%d) : ", voterCount + 1, candidateCount);
    scanf("%d", &choice);
    while (getchar() != '\n'); // Input buffer clear kora 
    if (choice >= 1 && choice <= candidateCount) {
        allCandidates[choice - 1].votes++;
        printf("Vote Casted , Skibidi Yes Yes Yes! \n");
    } else {
        printf("Bro what?  Invalid choice. LMAO vote void gelo\n");
    }
}

// Vote gononar function 
void getResults(int numVoters) {
    int maxVotes = 0, totalVotes = 0;
    int winnerIndices[MAX_C];
    int winnerCount = 0;
    int winnerIndex = -1;
    for (int i = 0; i < candidateCount; i++) {
        totalVotes += allCandidates[i].votes;
        if (allCandidates[i].votes > maxVotes) {
            maxVotes = allCandidates[i].votes;
            winnerCount = 1;
            winnerIndices[0] = i;
        } else if (allCandidates[i].votes == maxVotes) {
            winnerIndices[winnerCount++] = i;
        }
    }
    if (winnerCount == 1) {
        printf("\n Bijoyi: %s  (%d vote, %.1f%%)!!\n", allCandidates[winnerIndices[0]].name, maxVotes, (float)maxVotes * 100 / totalVotes);
        printf("Once again %s \n", allCandidates[winnerIndices[0]].name);
    } else {
        printf("\nTie hoye geche bro\n");
        for (int i = 0; i < winnerCount; i++) {
            printf("%s\n", allCandidates[winnerIndices[i]].name);
        }
        printf("\nRevote required!\n");
        for (int i = 0; i < candidateCount; i++) {
            allCandidates[i].votes = 0; // Reset votes for revote
        }
        for (int i = 0; i < numVoters; i++) {
            getVotes(i);
        }
        getResults(numVoters); // Recursive call for revote
    }
}

int main() {
    printf("Prathider songkha likhun (Minimum 1, Max 10) : ");
    scanf("%d", &candidateCount);
    while (getchar() != '\n'); // Input buffer clear kora
    if (candidateCount > 10 || candidateCount <= 0) {
        printf("Bro... invalid input . Program Bondho hocche \n\n");
        return 0;
    }
    for (int i = 0; i < candidateCount; i++) {
        fillCandidate(i);
    }
    int numVoters;
    printf("Voter songkha likhun (Min 1) : ");
    scanf("%d", &numVoters);
    while (getchar() != '\n'); // Input buffer clear kora
    if (numVoters <= 0) {
        printf("Voter songkha at least 1 lagbe bro . Rater vote nei na! \n\n");
        return 0;
    }
    for (int i = 0; i < numVoters; i++) {
        getVotes(i);
    }
    getResults(numVoters); // Vote gonona & folafol dekhanor function call kora
    return 0;
}
