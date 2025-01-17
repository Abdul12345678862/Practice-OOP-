import  java.util.Scanner;
  
public class Practice {
    private int[][] data; // 2D array to store matrix elements
    private int rows;     // Number of rows in the matrix
    private int cols;     // Number of columns in the matrix

    // Default constructor - Initializes the matrix with zeros
    // Takes the number of rows and columns as arguments
    public Practice(int rows, int cols) {
        this.rows = rows; // Set the number of rows
        this.cols = cols; // Set the number of columns
        data = new int[rows][cols]; // Create a 2D array for the matrix with all elements initialized to 0
    }
    // Copy constructor
    public Practice(Practice other) {
        this.rows = other.rows; 
        this.cols = other.cols; 
        this.data = new int[rows][cols]; 

        // Copy the elements from the other matrix
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                this.data[i][j] = other.data[i][j]; 
            }
        }
    }

    // Method to display the matrix in a readable format
    public void display() {
        for (int i = 0; i < rows; i++) { // Loop through each row
            for (int j = 0; j < cols; j++) { // Loop through each column in the row
                System.out.print(data[i][j] + " "); // Print the value in the matrix
            }
            System.out.println(); // Move to the next line after printing all columns of a row
        }
    }

    public void fill(){
        Scanner var = new Scanner(System.in);
        System.out.println("Enter 3X3 matrix");
        for(int i =0; i < rows; i++){
            for(int j=0; j<cols; j++){
                System.out.print("Enter ("+i+","+j+"):");
                data[i][j] = var.nextInt();
            }
        }
    }
    public Practice add(Practice other){
        if(this.rows != other.rows || this.cols != other.cols ){
            System.out.println("Matrix sizes don't match! Cannot add.");
            return this;
        }
        Practice result = new Practice(rows,cols);
        for(int i = 0; i<rows; i++){
            for(int j=0; j<cols; j++){
                result.data[i][j] = this.data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
    public static void main(String[] args) {
        Practice matrix1 = new Practice(3,3);
        matrix1.fill();
        matrix1.display();
    }
}
