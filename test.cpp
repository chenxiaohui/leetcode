
    bool search(int A[], int n, int target) {
        bool found = false;
        if (n > 0) {
          int low = 0;
          int high = n - 1;
          while (low + 1 < high) {
            int mid = low + (high - low) / 2;
            if (A[mid] > A[low]) {
              if (target < A[mid] && target > A[low]) {
                high = mid;
              } else if (target == A[mid] || target == A[low]) {
                found = true;
                break;
              } else {
                low = mid;
              }
            } else if (A[mid] < A[low]) {
              if (target > A[mid] && target < A[low]) {
                low = mid;
              } else if (target == A[mid] || target == A[low]) {
                found = true;
                break;
              } else {
                high = mid;
              }
            } else {
              high = mid;
            }
          }
          if (A[low] == target || A[high] == target) {
            found = true;
          }
        }
        return found;
    }
