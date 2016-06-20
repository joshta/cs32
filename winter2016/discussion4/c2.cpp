  void someFunc (vector<int> v) {
      for (int i = 0; i < v.size(); i++) {
          for (int j = i; j > 0; j /= 2) {
              if (v[j] == v[i]) {
                  cout << v[i] << endl;
              }
          }
      }
  }
