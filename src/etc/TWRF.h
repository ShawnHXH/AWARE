#ifndef WRF_TWRF_H
#define WRF_TWRF_H

#include "RF.h"

namespace wrf {

    /* Trees Weighting Random Forest.

    Out-Of-Bag, which is the training data subset generated by Bagging and not
    involved in building decision tree, is used to evaluate the tree. Then use
    its accuracy on OOB predictions as voting weights.

    Reference:
    [1] Li, Wang, Ding, Dong. Trees Weighting Random Forest Method for Classifying High-Dimensional Noisy Data.
        IEEE International Conference on E-Business Engineering, 2010.
    [2] Shahhosseini, Hu. Improved Weighted Random Forest for Classification Problems.
        Progress in Intelligent Decision Science, 2020.
    */
    class TWRF: public RandomForestClassifier {
    public:
        explicit TWRF(
            int nEstimators = 100,
            int maxDepth = 10,
            int randomState = -1,
            float maxSamplesRatio = 0.8,
            MaxFeature maxFeatures = MaxFeature::SQRT,
            int minSamplesSplit = 2,
            int minSamplesLeaf = 1,
            double minSplitGain = 0.0
        );

        Vector predict(const Matrix &test, const Matrix &train);

    private:
        Vector estimatorsW;

        void getWeights(const Matrix &train);
    };

}

#endif //WRF_TWRF_H
