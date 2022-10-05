#include <stdio.h>
#include <iostream>
#include <vector>

#include "define.h"

char getLetterGrade(double midtermGrade, double finalExamGrade) {
	//Check if Grades are valid
	if (midtermGrade < 0.0 || midtermGrade > 10.0) return '0';
	if (finalExamGrade < 0.0 || finalExamGrade > 10.0) return '0';

	double averageGrade = midtermGrade * 0.4 + finalExamGrade * 0.6;

	if (averageGrade < 4.0) return 'F';
	else if (averageGrade >= 4.0 && averageGrade < 5.5) return 'D';
	else if (averageGrade >= 5.5 && averageGrade < 7.0) return 'C';
	else if (averageGrade >= 7.0 && averageGrade < 8.5) return 'B';
	else if (averageGrade >= 8.5) return 'A';
};

int main() {
	FILE* pFile;

#if BOUNDARY_TEST
	pFile = fopen("boundaryValue/testcases.txt", "r");
#endif

#if EQUIVALENCE_TEST
	pFile = fopen("equivalencePartitioning/testcases.txt", "r");
#endif

	if (pFile != NULL) {
		int numOfTest;
		int passedTests = 0;
		std::vector<int> failedTestList;

		fscanf(pFile, "%d\n\n", &numOfTest);

		for (int i = 0; i < numOfTest; i++) {
			int testID;
			double midtermGrade, finalExamGrade;
			char expected;

			fscanf(pFile, "ID: %d\n", &testID);
			fscanf(pFile, "VALUE: %lf %lf\n", &midtermGrade, &finalExamGrade);
			fscanf(pFile, "EXPECTED: %c\n\n", &expected);

			char output = getLetterGrade(midtermGrade, finalExamGrade);

			printf("TEST ID: %d\n", testID);
			printf("INPUT: %lf %lf\n", midtermGrade, finalExamGrade);
			printf("EXPECTED OUTPUT: %c\n", expected);
			printf("ACTUAL OUTPUT: %c\n", output);

			if (output == expected) {
				printf("PASSED\n");
				passedTests++;
			}
			else {
				printf("FAILED\n");
				failedTestList.push_back(testID);
			}

			printf("\n");
		}

		printf("%d OUT OF %d CASES PASSED.\n", passedTests, numOfTest);

		printf("TEST FAILED: ");

		for (int i = 0; i < failedTestList.size(); i++) {
			printf("%d, ", failedTestList[i]);
		}
	}

	return 0;
}