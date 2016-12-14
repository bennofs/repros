#include <QWidget>

class MainClass : public QWidget {
  Q_OBJECT

  private:
    QWidget dependent;

  public:
    MainClass() {
      this->setWindowTitle("base");
      dependent.setWindowTitle("dependent");

      this->resize(200, 200);
      dependent.resize(40, 200);

      this->setStyleSheet("background-color: steelblue");
      dependent.setStyleSheet("background-color: black");

      this->show();
      dependent.show();

      move(300, 300);
    }

    virtual void moveEvent(QMoveEvent*) override {
      dependent.move(x() + 200 + 20, y());
    }

    virtual ~MainClass() {}
};
