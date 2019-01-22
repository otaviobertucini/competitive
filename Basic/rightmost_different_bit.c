//https://practice.geeksforgeeks.org/problems/rightmost-different-bit/0

int toBinary(int a, int b){
    int count = 0;
    int i=a;
    int j=b;
    for(;;i/=2, j/=2){
        count++;
        if((i%2 != j%2) || i == 0 || j == 0)
            return count;
    }
    return -1;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", toBinary(a, b));

	return 0;
}
