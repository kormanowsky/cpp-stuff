#include <iostream>

using namespace std;
typedef int* int2;
//Числа
int getDigit(int n, int pos){
    int dec = 1;
    while(10*dec <= n) dec *= 10;
    for(int i = 0; i < pos; ++i) dec /= 10;
    return n / dec;
}
int getSumDigits(int n){
    int dec, sum = 0;
    while(n != 0 ){
           dec = n %10;
           sum = sum + dec;
           n = n/10;
    }
    return sum;
}
int getMultDigits(int n){
    int dec, m = 1;
    while(n != 0 ){
           dec = n %10;
           m = m * dec;
           n = n/10;
    }
    return m;
}
int getCountDigits(int n){
    int count = 1;
    int dec = 1;
    while(10*dec <= n){
        dec *= 10;
        count++;
    }
    return count;
}
bool isSingle(int n){
    for(int i = 2; i <= n/2; ++i){
        if(n%i == 0) return false;
    }
    return true;
}
void swap(int* int1, int* int2){
    int t = *int1;
    *int1 = *int2;
    *int2 = t;
}
int sign(int n){
    if(n<0) return -1;
    else return (n==0) ? 0 : 1;
}
void writeMatrixFromNumber(int n = 10, int k = 1){
    for(int i = 0;i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << k << " ";
        }
        cout << endl;
    }
}
int previousMemoryField(int *n){
    return *(n-1);
}
int nextMemoryField(int *n){
    return *(n+1);
}
//Массивы
void inputArray(int* arrayToInput, int count){
    for(int i = 0; i < count; ++i){
        cin >> arrayToInput[i];
    }
}
void outputArray(int* arr, int c, string delimiter){
    for(int i = 0; i < c; ++i){
        cout << arr[i] << delimiter;
    }
}
void input2dArray(int* arr, int cols, int rows){
    for(int i = 0; i < rows; ++i){
        inputArray(&arr[i],cols);
    }
}
void output2dArray(int* arr, int cols, int rows, string colsDelimiter, string rowsDelimiter){
    for(int i = 0; i < rows; ++i){
        outputArray(&arr[i],cols,colsDelimiter);
        cout << rowsDelimiter;
    }

}
void input2dDynArray(int2 *arr, int cols, int rows){
    for(int i = 0; i < rows; ++i){
        inputArray(arr[i],cols);
    }
}
void output2dDynArray(int2 *arr, int cols, int rows, string colsDelimiter,string rowsDelimiter){
    for(int i = 0; i < rows; ++i){
        outputArray(arr[i],cols,colsDelimiter);
        cout << rowsDelimiter;
    }


}
void addToArray(int* arr, int v, int p, int* c){
    int _c = *c;
    for(int i = _c; _c >= p; _c--){
        arr[i] = arr[i-1];
    }
    arr[p] = v;
    *c += 1;
}
void removeFromArray(int* arr, int pos, int* count){
    for(int i = pos; i < *count-1; ++i){
        arr[i] = arr[i+1];
    }
    *count -= 1;
}
void removeValueFromArray(int* arr, int value, int* count){
    for(int i = 0; i < *count; ++i){
        if(arr[i] == value) removeFromArray(arr,i,count);
    }
}
void removeRangeFromArray(int* arr, int pos1, int pos2, int* count){
    if(pos1 == pos2) removeFromArray(arr,pos1,count);
    if(pos1 > pos2) swap(pos1,pos2);
    for(int i = 0; i < (pos2 - pos1); ++i){
        removeFromArray(arr,pos1,count);
    }
}
void bubbleSortAsc(int* arr, int c){
    for(int k = 0; k < c + 1; ++k){
         for(int i = 0; i < c - 1; ++i){
             if(arr[i+1] < arr[i]){
                 int temp = arr[i];
                 arr[i] = arr[i+1];
                 arr[i+1] = temp;
             }
         }
    }
}
void bubbleSortDesc(int* arr, int c){
    for(int k = 0; k < c + 1; ++k){
         for(int i = 0; i < c - 1; ++i){
             if(arr[i+1] > arr[i]){
                 int temp = arr[i];
                 arr[i] = arr[i+1];
                 arr[i+1] = temp;
             }
         }
    }
}
void filterLess(int* arr, int v, int c){
    for(int i = 0; i < c; ++i){
        if(arr[i] < v){
            removeFromArray(arr,i,&c);
        }
    }
}
void filterMore(int* arr, int v, int c){
    for(int i = 0; i < c; ++i){
        if(arr[i] > v){
            removeFromArray(arr,i,&c);
        }
    }
}
void filterNegative(int* arr, int c, bool allowZero){
    int v = -1;
    if(allowZero) v = 0;
    filterMore(arr,v,c);
}
void filterPositive(int* arr, int c, bool allowZero){
    int v = 1;
    if(allowZero) v = 0;
    filterLess(arr,v,c);
}
void swapInArray(int* arr, int c, int pos1, int pos2){
    if(pos1 > c-1 || pos2 > c-1) return;
    int t = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = t;
}
void swapArrayRows(int *arr[], int row1, int row2, int cols){

        int b[cols],c[cols];
        for(int j = 0; j < cols; ++j){
            b[j] = arr[row1][j];
            c[j] = arr[row2][j];
            arr[row2][j] = b[j];
            arr[row1][j] = c[j];

        }
}
void swapDynArrayRows(int2 *arr, int row1, int row2, int cols){

        int* b = new int[cols]; int* c = new int[cols];
        for(int j = 0; j < cols; ++j){
            b[j] = arr[row1][j];
            c[j] = arr[row2][j];
            arr[row2][j] = b[j];
            arr[row1][j] = c[j];

        }


        delete [] b; delete [] c;


}
void bubbleSortAsc__swapInArray(int* arr, int c){
    for(int k = 0; k < c + 1; ++k){
         for(int i = 0; i < c - 1; ++i){
             if(arr[i+1] < arr[i]){
                 swapInArray(arr,c,i,i+1);
             }
         }
    }
}
void bubbleSortDesc__swapInArray(int* arr, int c){
    for(int k = 0; k < c + 1; ++k){
         for(int i = 0; i < c - 1; ++i){
             if(arr[i+1] > arr[i]){
                 swapInArray(arr,c,i,i+1);
             }
         }
    }
}
void reverse(int* arr, int c){
    for(int i = 0; i <= c/2; ++i){
        int t = arr[i];
        arr[i] = arr[c-1-i];
        arr[c-1-i] = t;
    }
}
void reverseRange(int* arr, int c, int pos1, int pos2){
    if(pos1 > c-1 || pos2 > c-1) return;
    if(pos1 == pos2) return;
    if(pos1 > pos2) swap(&pos1,&pos2);
    for(int i = 0; i <= (pos2-pos1);++i){
        int t = arr[pos1+i];
        arr[pos1+i] =  arr[pos2-i];
        arr[pos2-i] = t;
    }
}
void shiftArrayRight(int* arr, int v, int c){
    for(int i = 0; i < v-1; ++i){
        for(int j = 0; j < c-1; ++j){
            swapInArray(arr,c,j,j+1);
        }
    }
}
void shiftArrayLeft(int* arr, int v, int c){
    for(int i = c-1; i < c-v-1; ++i){
        for(int j = c-2; j > -1; --j){
            swapInArray(arr,c,j,j+1);
        }
    }
}
void shiftArray(int* arr, int v, int c){
    if(v > 0) shiftArrayRight(arr,v,c);
    else shiftArrayLeft(arr,-v,c);
}
void fillArrayRange(int* arr, int v, int c, int pos1, int pos2){
    if(pos1 > c-1 || pos2 > c-1) return;
    for(int i = pos1; i <= pos2; ++i){
        arr[i] = v;
    }
}
void fillArray(int* arr, int v, int c){
    fillArrayRange(arr,v,c,0,c-1);
}
bool inArray(int* arr, int v, int c){
    for(int i = 0; i < c; ++i){
        if(arr[i] == v) return true;
    }
    return false;
}
int timesInArray(int* arr, int v, int c){
    if(!inArray(arr,v,c)) return 0;
    int times = 0;
    for(int i = 0; i < c; ++i){
        if(arr[i] == v) times++;
    }
    return times;
}
int getMin(int* arr, int c){
    int min = arr[0];
    for(int i = 1; i < c; ++i){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}
int getMax(int* arr, int c){
    int max = arr[0];
    for(int i = 1; i < c; ++i){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}
int getFirstPos(int* arr, int v, int c){
    for(int i = 0; i < c; ++i){
        if(arr[i] == v) return i;
    }
    return -1;
}
int getNthPos(int* arr, int v, int c, int n){
    if(timesInArray(arr,v,c) < n) return -1;
    int pos = 0;
    for(int i = 0; i < c; ++i){
        if(arr[i] == v){
            if(pos < n){
                pos++;
            }else{
                return i;
            }
        }
    }
    return -1;
}
int getLastPos(int* arr, int v, int c){
    int pos = -1;
    for(int i = 0; i < c; ++i){
        if(arr[i] == v) pos = i;
    }
    return pos;
}
int getSecondMin(int* arr, int c){
    int* b = arr;
    removeValueFromArray(b,getMin(b,c),&c);
    return getMin(b,c);
}
int getNthMin(int* arr, int c, int n){
    int* b = arr;
    for(int i = 0; i < n; ++i){
        removeValueFromArray(b,getMin(b,c),&c);
    }
    return getMin(b,c);
}
int getSecondMax(int* arr, int c){
    int* b = arr;
    removeValueFromArray(b,getMax(b,c),&c);
    return getMax(b,c);
}
int getNthMax(int* arr, int c, int n){
    int* b = arr;
    for(int i = 0; i < n; ++i){
        removeValueFromArray(b,getMax(b,c),&c);
    }
    return getMax(b,c);
}
int timesMinInArray(int* arr, int c){
    int min = getMin(arr,c);
    return timesInArray(arr,min,c);
}
int timesMaxInArray(int* arr, int c){
    int max = getMax(arr,c);
    return timesInArray(arr,max,c);
}
int getArraySum(int *arr, int c){
    int sum = 0;
    for(int i = 0; i < c; ++i){
        sum += arr[i];
    }
    return sum;
}
int getArrayMult(int* arr, int c){
    int mult = 1;
    for(int i = 0; i < c; ++i){
        mult *= arr[i];
    }
    return mult;
}
int getCountIfDivides(int *arr, int v, int c){
    int count = 0;
    for(int i = 0; i < c; ++i){
        if(arr[i]%v == 0) count++;
    }
    return count;
}
int getSumIfDivides(int *arr, int v, int c){
    int sum = 0;
    for(int i = 0; i < c; ++i){
        if(arr[i] % v == 0) sum += arr[i];
    }
    return sum;
}
int getCountCommonElements(int* arr1, int c1, int* arr2, int c2, bool strict = false){
    int count = 0;
    for(int i = 0; i < c1; ++i){
        if(inArray(arr2,arr1[i],c2) && (!strict || timesInArray(arr2,arr1[i],c2) == 1)) count++;
    }
    return count;
}
void filterUnique(int* arr, int *c){
    for(int i = 0; i < *c; ++i){
        if(timesInArray(arr,arr[i],*c) > 1){
            while(timesInArray(arr,arr[i],*c) > 1){
                for(int j = i+1; j < *c; ++j){
                    if(arr[j] == arr[i]){
                        removeFromArray(arr,j,c);
                    }
                }
            }
        }
    }
}
//Динамические массивы
void expandDynamicArray(int* arr, int* c, int b){
    cout << "In function expandDynamicArray(): ";
    outputArray(arr,*c," ");
    cout << endl;
    int nc = *c + b;
    int* t = new int[nc];
    for(int i = 0; i < *c; ++i){
        t[i] = arr[i];
    }
    delete [] arr;
    arr = t;
    cout << "In function expandDynamicArray() after actions: ";
    outputArray(arr,*c," ");
    cout << endl;
    *c = nc;
}
void collapseDynamicArray(int* arr, int* c, int b){
    int* t = new int[*c - b];
    for(int i = 0; i < *c - b; ++i){
        t[i] = arr[i];
    }
    delete [] arr;
    arr = t;
    *c -= b;
}
void expandAndAddToDynamicArray(int* arr, int v, int *c, int pos){
    cout << "In function expandAndAddToDynamicArray(): ";
    outputArray(arr,*c," ");
    cout << endl;
    expandDynamicArray(arr,c,1);
    cout << "In function expandAndAddToDynamicArray() after action 1: ";
    outputArray(arr,*c," ");
    cout << endl;
    addToArray(arr,v,pos,c);
    cout << "In function expandAndAddToDynamicArray() after action 1: ";
    outputArray(arr,*c," ");
    cout << endl;
}
void deleteDynamicArray(int* arr){
    delete [] arr;
}
int mergeDynamicArrays(int* a, int ca, int* b, int cb){
    expandDynamicArray(a,&ca,cb);
    for(int i = 0; i < cb; ++i){
        a[i+ca] = b[i];
    }
    return ca;
}
int main()
{
    int n = 10;
    int a[n] = {1,2,3,1,2,3,1,2,3,1};
    filterUnique(a,&n);
    outputArray(a,n," ");

}
