  // [!] Consider N = v1.size() and M = v2.size()
  void someFunc (vector<int> v1, vector<int> v2) {
      for (int i = 0; i < v1.size(); i++) {
          for (int j = 0; j < v2.size(); j += 2) {
              if (v1[i] == v2[j]) {
                  cout << v1[i] << endl;
              }
          }
      }
  }
