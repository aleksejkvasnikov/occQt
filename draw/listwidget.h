#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QQuickWidget>
#include <memory>

class MyModel;

class ListWidget : public QQuickWidget
{
public:
    ListWidget(std::shared_ptr<MyModel> model, QWidget *parent=nullptr);
    std::shared_ptr<MyModel> model() const;
private:
    std::shared_ptr<MyModel> m_model;
};

#endif // MAPWIDGET_H
