void knapsack(int ** sack, int ** sackAnswers, int ** objects, int sackCapacity, int numberOfObjects);
void getAnswer (int ** sackAnswers, int ** objects, int sackCapacity, int numberOfObjects);
void writeFile(char* filename, int sackCapacity, int ** objects, int numberOfCopies);
void readNumbers(char* filename, int * array);
void readFile(char* filename, int ** objects, int sackCapacity, int numberOfObjects);