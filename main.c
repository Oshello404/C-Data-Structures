int Insert(int value, int A[], int n)
{
    // insert value into A[], return new length n
    int pos, old, new, count;
    new = value;
    count = 0;
    
    if(n == 0){
        A[0] = value;
        return 1;
    }
    
    for(int i = 0; i < n; i++){
        if(value >= A[0]){
            pos = 0;
            count = n;
            break;
        }
        else if(A[n-1-i] >= value){
            pos = n-i;
            break;
        }
        else{
            count++;
        }
    }
    
    for(int i = 0; i < count+1; i++){
        old = A[pos+i];
        A[pos+i] = new;
        new = old;
    }
    return n+1;
}

int Delete(int value, int A[], int n)
{
    // delete value from A[], return new length n
    for(int i = 0; i < n; i++){
        if(A[i] == value){
            for(int j = i; j < n; j++){
                A[j] = A[j+1];
            }
            break;
        }
    }
    return n-1;
}

int Exist(int value, int A[], int n){
    // check whether value exists in array A[]
    for(int i = 0; i < n; i++){
        if(A[i] == value){
            return 1;
        }
    }
    return 0;
}

int Update_one(int old_value, int new_value, int A[], int n)
{
    n = Delete(old_value, A, n);
    n = Insert(new_value, A, n);
    return n;
}

int Update_all(int old_value_min, int old_value_max, int new_value, int A[], int n)
{
    // change old_value in range (inclusive) from old_value_min to old_value_max to new_value, return new length n
    int posStart, posEnd, lowerBound, upperBound;
    lowerBound = old_value_min;
    upperBound = old_value_max;
    
    for(int i = 0; i < (old_value_max - old_value_min) + 1; i++){
        if(Exist(lowerBound, A, n) == 0){
            lowerBound++;
        }
        else{

            for(int j = 0; j < (old_value_max - old_value_min) + 1; j++){
                if(Exist(upperBound, A, n) == 0){
                    upperBound--;
                }
                else {

                    for(int k = 0; k < n; k++){
                        if(A[k] == upperBound){
                            posStart = k;

                            break;
                        }
                    }
                    for(int k = 0; k < n; k++){
                        if(A[n-1-k] == lowerBound){
                            posEnd = n-1-k;

                            break;
                        }
                    }
                    for(int k = 0; k < (posEnd-posStart)+1; k++){
                        n = Delete(A[posStart], A, n);
                    }
                    for(int k = 0; k < (posEnd-posStart)+1; k++){
                        n = Insert(new_value, A, n);
                    }
                    return n;
                }

            }
        }   

    }
    return n;
}

void Print(int A[], int n)
{
    for(int i =0; i < n; i++){
	    printf("%d ", A[i]);
	}
}

int main()
{
    int A[100];
    int n; // the number of integers in A
    int value, value_min, value_max, new_value;

    // printf("Array initialization: \n");
    // printf("How many integers in array initially: ");
    scanf("%d", &n);
    // printf("What are the integers: ");
    int temp = 0;
    for(int i=0; i<n; i++){
        scanf("%d", &value);
        temp = Insert(value, A, temp);
    }

    // printf("Input a value for insertion: ");
	scanf("%d", &value);
	n = Insert(value, A, n);

	// printf("Input a value for deletion: ");
	scanf("%d", &value);
	n = Delete(value, A, n);

	// printf("Input the old and new values for update(one): ");
	scanf("%d%d", &value, &new_value);
	n = Update_one(value, new_value, A, n);

    // printf("Input the min old value, max olf value and new value for update(all): ");
	scanf("%d%d%d", &value_min, &value_max, &new_value);
	n = Update_all(value_min, value_max, new_value, A, n);

    // printf("Current array: \n");
	Print(A, n);

	return 0;
}