public class BubbleSort {
	public void sortArray(int[] array) {
		for (int i = array.length - 1; i > 0; i--) {
			for (int j = 0; j < i; j++) {
				if (array[j] > array[j + 1]) {
					int value = array[j+1];
		            array[j+1] = array[j];
		            array[j] = value;
				}
			}
		}
	}

	public void printArray(int[] array) {
		for (int i = 0; i < array.length; i++) {
			System.out.printf("%d \t", array[i]);
		}
		System.out.println();
	}

	public static void main(String[] args) {
		BubbleSort bubbleSort = new BubbleSort();
		int[] array = { 10, 5, 40, 12, 34, 44, 12, 11, 9 };
		bubbleSort.sortArray(array);
		bubbleSort.printArray(array);
	}
}