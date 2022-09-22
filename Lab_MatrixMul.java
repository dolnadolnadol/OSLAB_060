import java.util.Arrays;

public class Lab_MatrixMul {
    public static void main(String[] agrs){
        int[][] inputA = {{5, 6, 7}, {4, 8, 9}};
        int[][] inputB = {{6, 4}, {5, 7}, {1, 1}};
        MyData matA = new MyData(inputA);
        MyData matB = new MyData(inputB);
        int matC_r = matA.data.length;
        int matC_c = matB.data[0].length;
        MyData matC = new MyData(matC_r, matC_c);

        // q4
        Thread[][] thr = new Thread[matC_r][matC_c];
        for(int i = 0 ; i < inputA.length; i++){
            for(int j = 0; j < inputB[0].length; j++){
                thr[i][j] = new Thread(new MatrixMulThread(i, j, matA, matB, matC));
                thr[i][j].start();             
            }
        }
        try{
            for(int i = 0; i < inputA.length; i++){
                for(int j = 0; j < inputB[0].length; j++){
                    thr[i][j].join();
                }
            }
        }catch(Exception e){
            System.out.println(e);
        }
        matC.show();
    }
}

class MatrixMulThread implements Runnable{
    int processing_row;
    int processing_col;
    MyData datA, datB, datC;
    MatrixMulThread(int tRow, int tCol, MyData a, MyData b, MyData c){
        //q1
        processing_row = tRow;
        processing_col = tCol;
        datA = a;
        datB = b;
        datC = c;
    }
    /* q2 */ public void run(){
        // q3
        for(int i = 0; i < datA.data[0].length; i++){
            datC.data[processing_row][processing_col] += datA.data[processing_row][i]*datB.data[i][processing_col];
        }
        // System.out.println("perform sum of multiplication of assigned row and col");
    }
}
class MyData{
    int[][] data;
    MyData(int[][] m){
        data = m;
    }
    MyData(int r, int c){
        data = new int[r][c];
        for(int[] aRow : data){
            Arrays.fill(aRow, 0);
        }
    }
    void show(){
        System.out.println(Arrays.deepToString(data));
    }
}