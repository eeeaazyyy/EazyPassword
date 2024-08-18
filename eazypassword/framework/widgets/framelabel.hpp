#ifndef __ddfakywoqejbasdniqehuisadlnv123buyg386sayd
#define __ddfakywoqejbasdniqehuisadlnv123buyg386sayd

#include <ezlabel.hpp>

using namespace interfaces::widgets;

namespace framework { namespace widgets {

class FrameLabel : public EZLabel {
Q_OBJECT
public: 
    FrameLabel(QWidget* parent = nullptr);
    FrameLabel(const QString &text, QWidget* parent = nullptr);
    ~FrameLabel() override;

public slots:
    void setLabelName(const QString &text) override;
};

}}
#endif //__ddfakywoqejbasdniqehuisadlnv123buyg386sayd