#include "login.h"
#include "ui_login.h"

static QSqlDatabase bancoDeDados=QSqlDatabase::addDatabase("QSQLITE");

Login::Login(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Login)
{
  ui->setupUi(this);
  bancoDeDados.setDatabaseName("/home/eduardo/Teste/Infor");
  if(!bancoDeDados.open()){
      ui->banco->setText("Erro na conexão com o Banco de Dados");
    }else{
      ui->banco->setText("Conectado com o Banco de Dados");
    }
}

Login::~Login()
{
  delete ui;
}

void Login::on_pushButton_clicked()
{
  QString id=ui->cpLogin->text();
  QString senha=ui->CpSenha->text();

  if(!bancoDeDados.isOpen()){
        qDebug()<<"Banco de Dados não foi acessado";
        return;
    }
  QSqlQuery query;
  if(query.exec("select * from Funcionarios where ID='"+id+"' and PW='"+senha+"'")){
       int cont=0;
       while(query.next()){
           cont ++;
         }
       if(cont>0){
           this->close();
           Principal func;
         }else{
           ui->banco->setText("Login não efetuado");
           ui->cpLogin->clear();
           ui->CpSenha->clear();
           ui->cpLogin->setFocus();
         }
  }
}
