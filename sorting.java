import java.util.*;
class sorting{
    public static void main(String args[]){
        sorting ob=new sorting();
        Scanner sc=new Scanner(System.in);
        int a[]=new int[10];
        int i;
        System.out.println("Enter 10 elements");
        for(i=0;i<=9;i++){
            a[i]=sc.nextInt();
        }
        System.out.println("The original array");
        for(i=0;i<=9;i++){
            System.out.print(a[i]+" ,");
        }
        System.out.println("");
        ob.bubble(a);
        ob.selection(a);
        ob.insertion(a);
        sc.close();

    }
    void bubble(int a[]){
        int temp;
        int i,j;
        for(i=0;i<9;i++){
            for(j=0;j<10-i-1;j++){
                if(a[j]>a[j+1]){
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }

        }
        System.out.print("The array after sorting in bubble sort ");
        for(i=0;i<10;i++){
            System.out.print(a[i]+" ,");
        }
        System.out.println("");

    }
    void selection(int a[]){
        int i,j,mid,temp;
        for(i=0;i<9;i++){
            mid=i;
            for(j=i+1;j<10;j++){
                if(a[j]<a[mid])
                    mid=j;
            }
            temp=a[mid];
            a[mid]=a[i];
            a[i]=temp;
        }
        System.out.print("The array after sorting in selection sort ");
        for(i=0;i<10;i++){
            System.out.print(a[i]+" ,");
        }
        System.out.println("");
    }
    void insertion(int a[]){
        int i,j,key;
        for(i=1;i<10;++i){
            key=a[i];
            j=i-1;
            while(j>=0 && a[j]>key){
                a[j+1]=a[j];
                j=j-1;
            }
            a[j+1]=key;
        }
        System.out.print("The array after sorting in insertion sort ");
        for(i=0;i<10;i++){
            System.out.print(a[i]+" ,");
        }
        System.out.println("");
    }
}//class end