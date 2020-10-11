#include "mymodel.h"
#include "listwidget.h"

#include <QQmlContext>

ListWidget::ListWidget(std::shared_ptr<MyModel> model, QWidget *parent):
    QQuickWidget(parent),
    m_model(model)
{
    rootContext()->setContextProperty("myModel", m_model.get());
    setSource(QUrl(QStringLiteral("qrc:/ProjectTreeForm.ui.qml")));
}

std::shared_ptr<MyModel> ListWidget::model() const
{
    return m_model;
}
