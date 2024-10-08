#include "eval.h"

// Evaluation function for anomaly detection tasks
void evaluate_anomaly(int* y_true, int* y_pred, int size, float* results){
    int true_positive = 0;
    int true_negative = 0;
    int false_positive = 0;
    int false_negative = 0;

    for (int i = 0; i < size; i++) {
        if (y_true[i] == 1 && y_pred[i] == 1) {
            true_positive++;
        }
        else if (y_true[i] == -1 && y_pred[i] == -1) {
            true_negative++;
        }
        else if (y_true[i] == -1 && y_pred[i] == 1) {
            false_positive++;
        }
        else if (y_true[i] == 1 && y_pred[i] == -1) {
            false_negative++;
        }
    }

    // Calculate metrics
    results[ACCURACY] = (float)(true_positive + true_negative) / size;
    results[PRECISION] = (float)true_positive / (true_positive + false_positive);
    results[RECALL] = (float)true_positive / (true_positive + false_negative);
    results[F1_SCORE] =  2 * (results[PRECISION] * results[RECALL]) / (results[PRECISION] + results[RECALL]);

}
