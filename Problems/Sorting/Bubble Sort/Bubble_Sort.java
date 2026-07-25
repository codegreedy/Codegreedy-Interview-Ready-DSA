public class BubbleSort {
    static void swap(int[] arr, int j){
      int temp = arr[j];
      arr[j] = arr[j + 1];
      arr[j + 1] = temp;
    }
    static void bubbleSort(int[] arr) {
        int n = arr.length;

        for (int pass = 1; pass <= n - 1; pass++) {

            for (int j = 0; j < n - pass; j++) {

                if (arr[j] > arr[j + 1]) {
                    swap(arr, j);
                }
            }
        }
    }

    public static void main(String[] args) {

        int[] arr = {5, 3, 8, 4, 2};

        bubbleSort(arr);

        for (int num : arr) {
            System.out.print(num + " ");
        }
    }
}
