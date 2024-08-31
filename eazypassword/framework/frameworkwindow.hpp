#ifndef ___daorwdihgdufj21ujp1k3hbfa
#define ___daorwdihgdufj21ujp1k3hbfa

#include <QMainWindow>
#include <QGridLayout>

namespace framework { namespace window {

class EazyPasswordMainWindow : public QMainWindow {
Q_OBJECT
public:
    EazyPasswordMainWindow(QWidget* parent = nullptr);
    ~EazyPasswordMainWindow();

public:
    void fillForm(QWidget* centralWidget);

private:
    QWidget* centralWidget_;
};

}}
#endif //___daorwdihgdufj21ujp1k3hbfa