public class InsertSort{
  
  //从左到右向前比较,找到左边比自己小,右边比自己大的插入
  public void sort(int[] arr){
    for(int i = 0; i < arr.length; i++){
      for(int j = i;j > 0; j--){
        if(arr[j] < arr[j-1]){
          swap(arr,j,j-1);
        }else{
          break;
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
