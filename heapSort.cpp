#include <bits/stdc++.h>
typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<ll> vl;
#define pb push_back
// heapify function changes the array in to a heap
void heapify(vi &V, int N, int index) {

    int largest = index;
    int left = 2 * index;
    int right = left + 1;

    if (left <= N and V[left] > V[largest])
        largest = left;
    if (right <= N and V[right] > V[largest])
        largest = right;
    if (largest != index) {
        std::swap(V[largest], V[index]);
        heapify(V, N, largest);
    }
}

int main() {
  // for fast input and output
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
  
  // vector
    vi V;
    V.pb(0);
    int N;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        V.pb(a);
    }
    int start = floor(N / 2);
  
    for (int i = start; i > 0; i--)
        heapify(V, N, i);
    for (int i = 1; i <= N; i++)
        std::cout << V[i] << " ";

    for (int i = N; i >= 1; i--) {
        std::swap(V[1], V[i]);
        heapify(V, i - 1, 1);
    }
    std::cout << "\nSorted Array : ";
    for (int i = 1; i <= N; i++)
        std::cout << V[i] << " ";

    return 0;
}
