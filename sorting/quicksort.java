package sorting;

class Quick {
  int[] a;
  int n;
  Quick(int[] a) {
    this.a = a;
    this.n = a.length;
  }

  void sort(int l, int r) {
    if(l >= r) return;

    int pivotIndex = partition(l, r);
    sort(l, pivotIndex - 1);
    sort(pivotIndex + 1, r);
  }

  int partition(int l, int r) {
    /*
      take a partition, let's say the last element
      move all the element smaller than the pivot to the start
      move the pivot to end of the smaller elements
      return the index of the pivot
    */
    int pivot = a[r];
    int i = l-1;
    for(int j = l; j<r; j++) {
      if(a[j] < pivot) {
        i++;
        int tmp = a[j];
        a[j] = a[i];
        a[i] =  tmp;
      }
    }
    int tmp = a[i+1];
    a[i+1] = a[r];
    a[r] = tmp;
    return i+1;
  }
}

public class quicksort {
  public static void main(String[] args) {
    int[] arr = {5, 3, 8, 4, 2, 7, 1, 10};
    Quick quick = new Quick(arr);
    quick.sort(0, arr.length - 1);
    for(int i = 0; i < arr.length; i++) {
      System.out.print(arr[i] + " ");
    }
    System.out.println();
  }
}
