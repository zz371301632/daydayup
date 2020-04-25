public class BubbleSort{

  //从左到右,两两比较,找出最大的移动到最后边
  //依次类推,找出第二大、第三大移动到倒数第二位。。。
  public void sort(int[] arr){
    //执行n次
    for(int i = 0; i < arr.length; i++){
      //每次都从开头找
      for(int j = 1; j < arr.length; j++){
        if(arr[j] < arr[j - 1]){
          swap(arr,j,j-1);
        }
      }
    }
  }
  
  private void swap(int[] arr,int n1,int n2){
    int temp = arr[n1];
    arr[n1] = arr[n2];
    arr[n2] = temp;
  }
}
