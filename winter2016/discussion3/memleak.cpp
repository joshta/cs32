
int main() {
    int *leak=new int[5000];
    leak=new int[1000];
    return 0;
}
