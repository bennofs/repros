#include <QtCore>
#include <QMainWindow>
#include <QImage>
#include <QLabel>
#include <QtGui>
#include <QTimer>
#include <QDockWidget>
#include <QMenu>
#include <QMenuBar>

class MainClass : public QMainWindow {
private:
  QDockWidget *right, *bottom;
  QTimer* timer;
public:
  MainClass() : QMainWindow(nullptr) {
    this->setWindowTitle("dock-widget-glitch");

    {
      QImage image1;
      image1.load("image1.jpg");
      QLabel* label = new QLabel(this);
      label->setPixmap(QPixmap::fromImage(image1));
      label->setScaledContents(true);
      this->setCentralWidget(label);
    }

    addRightDock();
    addBottomDock();

    {
      QMenu* menu = this->menuBar()->addMenu("Views");
      QAction* rightAction = menu->addAction("Right");
      QAction* bottomAction = menu->addAction("Bottom");

      timer = new QTimer(this);

      connect(rightAction, &QAction::triggered, this, [this] {
          this->addRightDock();
      });

      connect(bottomAction, &QAction::triggered, this, [this] {
          this->addBottomDock();
      });
    }

    this->showMaximized();
  }

  void addRightDock() {
    QImage image2;
    image2.load("image2.jpg");
    QLabel* label = new QLabel(this);
    label->setPixmap(QPixmap::fromImage(image2));
    label->setScaledContents(true);

    right = new QDockWidget("right", this);
    right->setAllowedAreas(Qt::DockWidgetArea::RightDockWidgetArea);
    right->setWidget(label);
    this->addDockWidget(Qt::DockWidgetArea::RightDockWidgetArea, right);

    timer->singleShot(1300, [this]{
      this->right->close();
      this->timer->singleShot(200, [this] {
          QCoreApplication::quit();
      });
    });
  }

  void addBottomDock() {
    QImage image3;
    image3.load("image3.jpg");
    QLabel* label = new QLabel(this);
    label->setPixmap(QPixmap::fromImage(image3));
    label->setScaledContents(true);

    bottom = new QDockWidget("bottom", this);
    bottom->setAllowedAreas(Qt::DockWidgetArea::BottomDockWidgetArea);
    bottom->setWidget(label);
    this->addDockWidget(Qt::DockWidgetArea::BottomDockWidgetArea, bottom);
  }

  virtual ~MainClass() {}
};
