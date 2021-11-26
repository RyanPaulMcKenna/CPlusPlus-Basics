class Calculator
{
public:
    Calculator(); // Constructor to set initial status.
    void launch(); //To display initial instructions.
    void readInput(); // Get expression.
    void writeOutput(); // Displays result.
    bool run(); // Gets current status.
private:
    double num1, num2; // Stores numbers.
    char oper; // Stores input operator.
    bool status; // To store current status.
};
