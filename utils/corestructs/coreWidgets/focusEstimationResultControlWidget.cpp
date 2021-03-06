/**
 * \file focusEstimationResultControlWidget.cpp
 * \attention This file is automatically generated and should not be in general modified manually
 *
 * \date MMM DD, 20YY
 * \author autoGenerator
 */

#include "focusEstimationResultControlWidget.h"
#include "ui_focusEstimationResultControlWidget.h"
#include <memory>
#include "qSettingsGetter.h"
#include "qSettingsSetter.h"


FocusEstimationResultControlWidget::FocusEstimationResultControlWidget(QWidget *parent, bool _autoInit, QString _rootPath)
    : ParametersControlWidgetBase(parent)
    , mUi(new Ui::FocusEstimationResultControlWidget)
    , autoInit(_autoInit)
    , rootPath(_rootPath)
{
    mUi->setupUi(this);

    QObject::connect(mUi->scoreSpinBox, SIGNAL(valueChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->scoreROISpinBox, SIGNAL(valueChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->fullScoreSpinBox, SIGNAL(valueChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->boardProcessedCheckBox, SIGNAL(stateChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->bnoiseSpinBox, SIGNAL(valueChanged(double)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->wnoiseSpinBox, SIGNAL(valueChanged(double)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->sharpnessSpinBox, SIGNAL(valueChanged(double)), this, SIGNAL(paramsChanged()));
}

FocusEstimationResultControlWidget::~FocusEstimationResultControlWidget()
{

    delete mUi;
}

void FocusEstimationResultControlWidget::loadParamWidget(WidgetLoader &loader)
{
    std::unique_ptr<FocusEstimationResult> params(createParameters());
    loader.loadParameters(*params, rootPath);
    setParameters(*params);
}

void FocusEstimationResultControlWidget::saveParamWidget(WidgetSaver  &saver)
{
    saver.saveParameters(*std::unique_ptr<FocusEstimationResult>(createParameters()), rootPath);
}

void FocusEstimationResultControlWidget::getParameters(FocusEstimationResult& params) const
{
    params = *std::unique_ptr<FocusEstimationResult>(createParameters());
}


FocusEstimationResult *FocusEstimationResultControlWidget::createParameters() const
{

    /**
     * We should think of returning parameters by value or saving them in a preallocated place
     **/


    return new FocusEstimationResult(
          mUi->scoreSpinBox->value()
        , mUi->scoreROISpinBox->value()
        , mUi->fullScoreSpinBox->value()
        , mUi->boardProcessedCheckBox->isChecked()
        , mUi->bnoiseSpinBox->value()
        , mUi->wnoiseSpinBox->value()
        , mUi->sharpnessSpinBox->value()
    );
}

void FocusEstimationResultControlWidget::setParameters(const FocusEstimationResult &input)
{
    // Block signals to send them all at once
    bool wasBlocked = blockSignals(true);
    mUi->scoreSpinBox->setValue(input.score());
    mUi->scoreROISpinBox->setValue(input.scoreROI());
    mUi->fullScoreSpinBox->setValue(input.fullScore());
    mUi->boardProcessedCheckBox->setChecked(input.boardProcessed());
    mUi->bnoiseSpinBox->setValue(input.bnoise());
    mUi->wnoiseSpinBox->setValue(input.wnoise());
    mUi->sharpnessSpinBox->setValue(input.sharpness());
    blockSignals(wasBlocked);
    emit paramsChanged();
}

void FocusEstimationResultControlWidget::setParametersVirtual(void *input)
{
    // Modify widget parameters from outside
    FocusEstimationResult *inputCasted = static_cast<FocusEstimationResult *>(input);
    setParameters(*inputCasted);
}
