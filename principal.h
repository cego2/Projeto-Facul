#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QtSql>
#include <QMessageBox>
#include "empresa.h"
#include "funcionario.h"
#include <QFileDialog>
#include <algorithm>
#include <QStringList>


namespace Ui { class Principal; }


class Principal : public QMainWindow
{
  Q_OBJECT

public:
  explicit Principal(QWidget *parent = nullptr);
  ~Principal();

private slots:

  void on_BtnRegistrar_clicked();
  void on_Ordenar_clicked();
  void on_pushButton_clicked();
  void on_BtnRemover_clicked();
  void on_actionSalvar_3_triggered();
  void on_actionCarregar_triggered();
  void carregar();
  void on_tabela_cellDoubleClicked(int row, int column);

private:
  Ui::Principal *ui;
  Empresa empresa;
  Funcionario a;
  void AtualizaDados();
  void inserirNaTabela(Funcionario b, int linha);
};

#endif // PRINCIPAL_H
