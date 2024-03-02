#include <vector>
#include <array>

#define ARR_SIZE 50

using namespace std;

const std::string outPath = "/Users/kekoveca/Documents/Proga/sort_visualization/out/";

void BubbleSort(vector<int> values) {
  vector<array<int, ARR_SIZE>> snapshots;
  for (size_t idx_i = 0; idx_i + 1 < values.size(); ++idx_i) {
    for (size_t idx_j = 0; idx_j + 1 < values.size() - idx_i; ++idx_j) {
      if (values[idx_j + 1] < values[idx_j]) {
        swap(values[idx_j], values[idx_j + 1]);
      }
      array<int, ARR_SIZE> temp_arr;
      copy(values.begin(), values.end(), temp_arr.begin());
      snapshots.push_back(temp_arr);
    }
  }

  std::ofstream fileOut;
  std::string fileName = "BubbleSort.csv";
  fileOut.open(outPath + fileName);

  for(auto& sort_iter: snapshots) {
    for(auto& snap_iter: sort_iter) {
      fileOut << snap_iter << ",";
    }
  fileOut << "\n";
  }

  fileOut.close();
}

void ShakerSort(vector<int> values) {
  vector<array<int, ARR_SIZE>> snapshots;
  int left = 0;
  int right = values.size() - 1;
  while (left <= right) {
    for (int i = right; i > left; --i) {
      if (values[i - 1] > values[i]) {
        swap(values[i - 1], values[i]);
      }
      array<int, ARR_SIZE> temp_arr;
      copy(values.begin(), values.end(), temp_arr.begin());
      snapshots.push_back(temp_arr);
    }
    ++left;
    for (int i = left; i < right; ++i) {
      if (values[i] > values[i + 1]) {
        swap(values[i], values[i + 1]);
      }
      array<int, ARR_SIZE> temp_arr;
      copy(values.begin(), values.end(), temp_arr.begin());
      snapshots.push_back(temp_arr);
    }
    --right;
  }
  std::ofstream fileOut;
  std::string fileName = "ShakerSort.csv";
  fileOut.open(outPath + fileName);

  for(auto& sort_iter: snapshots) {
    for(auto& snap_iter: sort_iter) {
      fileOut << snap_iter << ",";
    }
  fileOut << "\n";
  }

  fileOut.close();
}

void CombSort(vector<int> values) {
  vector<array<int, ARR_SIZE>> snapshots;
  const double factor = 1.247; // Фактор уменьшения
  double step = values.size() - 1;

  while (step >= 1) {
    for (int i = 0; i + step < values.size(); ++i) {
      if (values[i] > values[i + step]) {
        swap(values[i], values[i + step]);
      }
      array<int, ARR_SIZE> temp_arr;
      copy(values.begin(), values.end(), temp_arr.begin());
      snapshots.push_back(temp_arr);
    }
    step /= factor;
  }
  // сортировка пузырьком
  for (size_t idx_i = 0; idx_i + 1 < values.size(); ++idx_i) {
    for (size_t idx_j = 0; idx_j + 1 < values.size() - idx_i; ++idx_j) {
      if (values[idx_j + 1] < values[idx_j]) {
        swap(values[idx_j], values[idx_j + 1]);
      }
      array<int, ARR_SIZE> temp_arr;
      copy(values.begin(), values.end(), temp_arr.begin());
      snapshots.push_back(temp_arr);
    }
  }
  std::ofstream fileOut;
  std::string fileName = "CombSort.csv";
  fileOut.open(outPath + fileName);

  for(auto& sort_iter: snapshots) {
    for(auto& snap_iter: sort_iter) {
      fileOut << snap_iter << ",";
    }
  fileOut << "\n";
  }

  fileOut.close();
}

void InsertionSort(vector<int> values) {
  vector<array<int, ARR_SIZE>> snapshots;
  for (size_t i = 1; i < values.size(); ++i) {
    int x = values[i];
    size_t j = i;
    while (j > 0 && values[j - 1] > x) {
      values[j] = values[j - 1];
      --j;
      array<int, ARR_SIZE> temp_arr;
      copy(values.begin(), values.end(), temp_arr.begin());
      snapshots.push_back(temp_arr);
    }
    values[j] = x;
    array<int, ARR_SIZE> temp_arr;
    copy(values.begin(), values.end(), temp_arr.begin());
    snapshots.push_back(temp_arr);
  }
  std::ofstream fileOut;
  std::string fileName = "InsertionSort.csv";
  fileOut.open(outPath + fileName);

  for(auto& sort_iter: snapshots) {
    for(auto& snap_iter: sort_iter) {
      fileOut << snap_iter << ",";
    }
  fileOut << "\n";
  }

  fileOut.close();
}

void SelectionSort(vector<int> values) {
  vector<array<int, ARR_SIZE>> snapshots;
  for (auto i = values.begin(); i != values.end(); ++i) {
    auto j = std::min_element(i, values.end());
    swap(*i, *j);
    array<int, ARR_SIZE> temp_arr;
    copy(values.begin(), values.end(), temp_arr.begin());
    snapshots.push_back(temp_arr);
  }
  std::ofstream fileOut;
  std::string fileName = "SelectionSort.csv";
  fileOut.open(outPath + fileName);

  for(auto& sort_iter: snapshots) {
    for(auto& snap_iter: sort_iter) {
      fileOut << snap_iter << ",";
    }
  fileOut << "\n";
  }

  fileOut.close();
}

int Partition(vector<int>& values, int l, int r) {
  vector<array<int, ARR_SIZE>> snapshots;
  int x = values[r];
  int less = l;

  for (int i = l; i < r; ++i) {
    if (values[i] <= x) {
      swap(values[i], values[less]);
      ++less;
    }
    array<int, ARR_SIZE> temp_arr;
    copy(values.begin(), values.end(), temp_arr.begin());
    snapshots.push_back(temp_arr);
  }
  swap(values[less], values[r]);

  std::ofstream fileOut;
  std::string fileName = "QuickSort.csv";
  fileOut.open(outPath + fileName, std::ios::app);

  for(auto& sort_iter: snapshots) {
    for(auto& snap_iter: sort_iter) {
      fileOut << snap_iter << ",";
    }
  fileOut << "\n";
  }

  fileOut.close();
  return less;
}

void QuickSortImpl(vector<int>& values, int l, int r) {
  if (l < r) {
    int q = Partition(values, l, r);
    QuickSortImpl(values, l, q - 1);
    QuickSortImpl(values, q + 1, r);
  }
}

void QuickSort(vector<int> values) {
  if (!values.empty()) {
    QuickSortImpl(values, 0, values.size() - 1);
  }
}

void MergeSortImpl(vector<int>& values, vector<int>& buffer, int l, int r) {
  vector<array<int, ARR_SIZE>> snapshots;
  if (l < r) {
    int m = (l + r) / 2;
    MergeSortImpl(values, buffer, l, m);
    MergeSortImpl(values, buffer, m + 1, r);

    int k = l;
    for (int i = l, j = m + 1; i <= m || j <= r; ) {
      if (j > r || (i <= m && values[i] < values[j])) {
        buffer[k] = values[i];
        ++i;
      } else {
        buffer[k] = values[j];
        ++j;
      }
      ++k;
    }
    for (int i = l; i <= r; ++i) {
      values[i] = buffer[i];
      array<int, ARR_SIZE> temp_arr;
      copy(values.begin(), values.end(), temp_arr.begin());
      snapshots.push_back(temp_arr);
    }
  }
  std::ofstream fileOut;
  std::string fileName = "MergeSort.csv";
  fileOut.open(outPath + fileName, std::ios::app);

  for(auto& sort_iter: snapshots) {
    for(auto& snap_iter: sort_iter) {
      fileOut << snap_iter << ",";
    }
  fileOut << "\n";
  }

  fileOut.close();
}

void MergeSort(vector<int> values) {
  if (!values.empty()) {
    vector<int> buffer(values.size());
    MergeSortImpl(values, buffer, 0, values.size() - 1);
  }
}

void HeapSort(vector<int> values) {
  vector<array<int, ARR_SIZE>> snapshots;
  std::make_heap(values.begin(), values.end());
  for (auto i = values.end(); i != values.begin(); --i) {
    std::pop_heap(values.begin(), i);
    array<int, ARR_SIZE> temp_arr;
    copy(values.begin(), values.end(), temp_arr.begin());
    snapshots.push_back(temp_arr);
  }
  std::ofstream fileOut;
  std::string fileName = "HeapSort.csv";
  fileOut.open(outPath + fileName);

  for(auto& sort_iter: snapshots) {
    for(auto& snap_iter: sort_iter) {
      fileOut << snap_iter << ",";
    }
  fileOut << "\n";
  }

  fileOut.close();
}