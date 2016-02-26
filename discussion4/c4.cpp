  // [!] Consider N = v1.size() and M = s.size()
  void someFunc (vector<int> v1, set<int> s) {
      for (int i = 0; i < v1.size(); i++) {
          if (s.find(v[i]) != s.end()) {
              cout << v1[i] << endl;
          }
      }
  }
