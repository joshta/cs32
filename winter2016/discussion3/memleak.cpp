
int main() {
    int *leakishere=new int[5000];
    leakishere=new int[1000];
    return 0;
}
