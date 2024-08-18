#include <QDebug>

#include "framelabel.hpp"

namespace framework { namespace widgets {

FrameLabel::FrameLabel(QWidget *parent) 
        : EZLabel(parent) {
}

FrameLabel::FrameLabel(const QString &text, QWidget *parent) 
        : EZLabel(text, parent) {
    setLabelName(text);
}

FrameLabel::~FrameLabel() {
    qInfo() << labelName() << "::~" << labelName();
}

void FrameLabel::setLabelName(const QString &text) {
    labelName_ = text;
    EZLabel::setText(text);
}

}}