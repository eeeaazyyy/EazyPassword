#ifndef ____djajfuehwjpgfcinrtyukmnbvcdfkl12nigr2
#define ____djajfuehwjpgfcinrtyukmnbvcdfkl12nigr2

#include <QWidget>
#include <QLabel>
#include <QLineEdit>

namespace ezpass { namespace widgets {

/*
 * InputLineEdit
 * 
 */

class InputLineEdit : public QWidget {
Q_OBJECT
public:
    explicit InputLineEdit(const QString& title, QWidget* parent = nullptr);
    explicit InputLineEdit(QWidget* parent = nullptr);
    ~InputLineEdit();

public: 
    virtual void setTextTitle(const QString& title);
    virtual QString textTitle() const;

    virtual QString lineEditText() const;

public slots:
    void setLineEditText(const QString& title);
    void clear();

protected:
    QLabel* title_;
    QLineEdit* lineEdit_;
};

}}

#endif // ____djajfuehwjpgfcinrtyukmnbvcdfkl12nigr2