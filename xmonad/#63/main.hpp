#include <QWidget>
#include <QDebug>
#include <QMoveEvent>
#include <QResizeEvent>

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

    virtual void moveEvent(QMoveEvent* event) override {
      qDebug() << "MOVE   " << event->oldPos() << "\t->" << event->pos();
      dependent.move(x() + width() + 20, y());
    }

    virtual void resizeEvent(QResizeEvent* event) override {
      qDebug() << "RESIZE " << event->oldSize() << "\t->" << event->size();
      dependent.resize(40, height());
      dependent.move(x() + width() + 20, y());
    }

    virtual ~MainClass() {}
};
