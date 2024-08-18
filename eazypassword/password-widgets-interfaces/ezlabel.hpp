#ifndef __dsadfa_asdwqv12kaj
#define __dsadfa_asdwqv12kaj

#include <QLabel>

namespace interfaces { namespace widgets {

class EZLabel : public QLabel {
public:
    explicit EZLabel(QWidget *parent = nullptr) : QLabel(parent), labelName_("EZLabel") {};
    explicit EZLabel(const QString &text, QWidget *parent = nullptr) : QLabel(text, parent), labelName_(text) {};
    ~EZLabel() {};
    
public:
    QString labelName() { return labelName_; };

public slots:
    virtual void setLabelName(const QString &text) = 0;

protected:
    QString labelName_;
};

}}
#endif