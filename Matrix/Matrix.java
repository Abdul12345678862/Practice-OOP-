// Matrix.java
public class Matrix {
    private int[][] data; // 2D array to store matrix elements
    private int rows;     // Number of rows in the matrix
    private int cols;     // Number of columns in the matrix

    // Default constructor - Initializes the matrix with zeros
    // Takes the number of rows and columns as arguments
    public Matrix(int rows, int cols) {
        this.rows = rows; // Set the number of rows
        this.cols = cols; // Set the number of columns
        data = new int[rows][cols]; // Create a 2D array for the matrix with all elements initialized to 0
    }

    // Copy constructor - Creates a new matrix that is a copy of the given matrix
    public Matrix(Matrix other) {
        this.rows = other.rows; // Copy the number of rows
        this.cols = other.cols; // Copy the number of columns
        this.data = new int[rows][cols]; // Create a new 2D array for the copy of the matrix

        // Copy each element from the 'other' matrix to this new matrix
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                this.data[i][j] = other.data[i][j]; // Copy the value at each position
            }
        }
    }

    // Assignment method - Copies the content of one matrix to another
    // This method performs a deep copy (not shallow)
    public Matrix assign(Matrix other) {
        // Check if the size of both matrices match
        if (this.rows != other.rows || this.cols != other.cols) {
            System.out.println("Matrix sizes don't match! Cannot assign.");
            return this; // If sizes don't match, return the current matrix without changes
        }

        // If sizes match, copy the elements from 'other' matrix to this matrix
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                this.data[i][j] = other.data[i][j]; // Copy value
            }
        }
        return this; // Return the current matrix after assignment
    }

    // Method to set a value at a specific row and column
    public void setValue(int row, int col, int value) {
        if (row < rows && col < cols) { // Check if the row and column are within bounds
            data[row][col] = value; // Set the value at the specified position
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

    // Main method (Driver) to test the functionality of the Matrix class
    public static void main(String[] args) {
        // Create a matrix of size 3x3
        Matrix matrix1 = new Matrix(3, 3);

        // Set values for the first matrix (matrix1)
        matrix1.setValue(0, 0, 1);
        matrix1.setValue(0, 1, 2);
        matrix1.setValue(0, 2, 3);
        matrix1.setValue(1, 0, 4);
        matrix1.setValue(1, 1, 5);
        matrix1.setValue(1, 2, 6);
        matrix1.setValue(2, 0, 7);
        matrix1.setValue(2, 1, 8);
        matrix1.setValue(2, 2, 9);

        // Display the first matrix
        System.out.println("Matrix 1:");
        matrix1.display();

        // Create another matrix using the copy constructor (copy of matrix1)
        Matrix matrix2 = new Matrix(matrix1);
        System.out.println("Matrix 2 (Copy of Matrix 1):");
        matrix2.display(); // Display matrix2

        // Create a third matrix and set initial values
        Matrix matrix3 = new Matrix(3, 3);
        matrix3.setValue(0, 0, 10);
        matrix3.setValue(0, 1, 11);
        matrix3.setValue(0, 2, 12);
        matrix3.setValue(1, 0, 13);
        matrix3.setValue(1, 1, 14);
        matrix3.setValue(1, 2, 15);
        matrix3.setValue(2, 0, 16);
        matrix3.setValue(2, 1, 17);
        matrix3.setValue(2, 2, 18);

        // Display the third matrix before assignment
        System.out.println("Matrix 3 before assignment:");
        matrix3.display();

        // Assign matrix1 to matrix3 using the assign method
        matrix3.assign(matrix1);

        // Display matrix3 after the assignment (should match matrix1)
        System.out.println("Matrix 3 after assignment (from Matrix 1):");
        matrix3.display();
    }
}
