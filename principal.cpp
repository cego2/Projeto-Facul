#include "principal.h"
#include "ui_principal.h"
#include <QInputDialog>


static QSqlDatabase bancoDeDados=QSqlDatabase::addDatabase("QSQLITE");

Principal::Principal(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::Principal)
{
  ui->setupUi(this);

      connect(ui->actionSalvar,SIGNAL(triggered()),this,SLOT(salvar()));
      connect(ui->actionCarregar,SIGNAL(triggered()),this,SLOT(carregar()));

  bancoDeDados.setDatabaseName("/home/eduardo/Teste/Infor");
    if(!bancoDeDados.open()){
      ui->banco->setText("Erro na conexão com o Banco de Dados");
    }else{
      ui->banco->setText("Conectado com o Banco de Dados");
    }
      ui->tabela->setSelectionBehavior(QAbstractItemView::SelectRows);
}

Principal::~Principal()
{
  delete ui;
}

void Principal::on_BtnRegistrar_clicked()
{
  Funcionario funcionario;
  int qnt_linhas;

    QString nome = ui->CpNome->text();
    QString rg = ui->CpRg->text();
    QString cpf = ui->CpCpf->text();
    QString end = ui->CpEnd->text();
    QString setor = ui->CpSetor->text();
    QString id = ui->CpLoguin->text();
    QString pw = ui->CpSenha->text();
    float slr = ui->CpSalario->text().toFloat();

    ui->CpNome->clear();
    ui->CpCpf->clear();
    ui->CpRg->clear();
    ui->CpEnd->clear();
    ui->CpSetor->clear();
    ui->CpLoguin->clear();
    ui->CpSenha->clear();
    ui->CpSalario->clear();

    funcionario.setNom(nome);
    funcionario.setCpf(cpf);
    funcionario.setSetor(setor);
    funcionario.setIdentidade(rg);
    funcionario.setEnd(end);
    funcionario.setID(id);
    funcionario.setPW(pw);
    funcionario.setSalario(slr);

    if(funcionario.getNom()== ""|| funcionario.getCpf() == "" || funcionario.getEnd() == ""|| funcionario.getSetor() ==""
       || funcionario.getIdentidade()==""|| funcionario.getID()=="" || QString::number(funcionario.getSalario())==""){
          QMessageBox::information(this, "", "Você adicionou informações inválidas");

      }else{
    qnt_linhas = ui->tabela->rowCount();
        ui->tabela->insertRow(qnt_linhas);
    ui->tabela->setItem(qnt_linhas,0,new QTableWidgetItem(funcionario.getNom()));
    ui->tabela->setItem(qnt_linhas,1,new QTableWidgetItem(funcionario.getEnd()));
    ui->tabela->setItem(qnt_linhas,2,new QTableWidgetItem(funcionario.getCpf()));
    ui->tabela->setItem(qnt_linhas,3,new QTableWidgetItem(funcionario.getIdentidade()));
    ui->tabela->setItem(qnt_linhas,4,new QTableWidgetItem(funcionario.getSetor()));
    ui->tabela->setItem(qnt_linhas,5,new QTableWidgetItem(funcionario.getID()));
    ui->tabela->setItem(qnt_linhas,6,new QTableWidgetItem(QString::number(funcionario.getSalario())));
    empresa.incluirFuncionario(funcionario);
    AtualizaDados();

    QSqlQuery cadastro;

    if(cadastro.prepare("insert into Funcionarios (Nome, CPF, RG, END, SETOR, ID, PW, Salario) values "
                       "('"+nome+"', '"+cpf+"', '"+rg+"', '"+end+"', '"+setor+"', '"+id+"', '"+pw+"', '"+slr+"')"));

    if(cadastro.exec()){
    QMessageBox::information(this, "", "Registrado no banco de dados");
      }else{
        QMessageBox::information(this, "", "Desculpe, registro no banco de dados falhou!");
      }
}}

void Principal::on_Ordenar_clicked()
{
      empresa.ordenar();
      ui->tabela->clearContents();
      for(int i = 0; i< empresa.size();i++){

          ui->tabela->setItem(i,0,new QTableWidgetItem(empresa[i].getNom()));
          ui->tabela->setItem(i,1,new QTableWidgetItem(empresa[i].getEnd()));
          ui->tabela->setItem(i,2,new QTableWidgetItem(empresa[i].getCpf()));
          ui->tabela->setItem(i,3,new QTableWidgetItem(empresa[i].getIdentidade()));              // Ordenando itens da tabela por nome.
          ui->tabela->setItem(i,4,new QTableWidgetItem(empresa[i].getSetor()));
          ui->tabela->setItem(i,5,new QTableWidgetItem(empresa[i].getID()));
          ui->tabela->setItem(i,6,new QTableWidgetItem(QString::number(empresa[i].getSalario())));
}}

void Principal::on_pushButton_clicked()
{
      empresa.ordenar2();
      ui->tabela->clearContents();
      for(int i = 0; i< empresa.size();i++){

          ui->tabela->setItem(i,0,new QTableWidgetItem(empresa[i].getNom()));
          ui->tabela->setItem(i,1,new QTableWidgetItem(empresa[i].getEnd()));
          ui->tabela->setItem(i,2,new QTableWidgetItem(empresa[i].getCpf()));
          ui->tabela->setItem(i,3,new QTableWidgetItem(empresa[i].getIdentidade())); // Ordenando itens da tabela por salario.
          ui->tabela->setItem(i,4,new QTableWidgetItem(empresa[i].getSetor()));
          ui->tabela->setItem(i,5,new QTableWidgetItem(empresa[i].getID()));
          ui->tabela->setItem(i,6,new QTableWidgetItem(QString::number(empresa[i].getSalario())));
        }}

void Principal::AtualizaDados()
{
  float maior = empresa.maiorSalario();
  float menor = empresa.menorSalario();
  float media = empresa.mediaDeSalario();

  ui->MostrarSalario->setText(QString::number(maior));
  ui->menorSal->setText(QString::number(menor));
  ui->MostrarMedia->setText(QString::number(media));

}

void Principal::inserirNaTabela(Funcionario b, int linha)
{
  ui->tabela->setItem(linha,0,new QTableWidgetItem(b.getNom()));
  ui->tabela->setItem(linha,1,new QTableWidgetItem(b.getEnd()));
  ui->tabela->setItem(linha,2,new QTableWidgetItem(b.getCpf()));
  ui->tabela->setItem(linha,3,new QTableWidgetItem(b.getIdentidade()));       // Inserindo dados recem digitados na tabela
  ui->tabela->setItem(linha,4,new QTableWidgetItem(b.getSetor()));
  ui->tabela->setItem(linha,5,new QTableWidgetItem(b.getID()));
  ui->tabela->setItem(linha,6,new QTableWidgetItem(QString::number(b.getSalario())));
}

void Principal::on_BtnRemover_clicked()
{
    int linha=ui->tabela->currentRow();
    QString id=ui->tabela->item(linha,0)->text();
    QSqlQuery excluir;
    excluir.prepare("delete from Funcionarios where Nome= id");
    if(excluir.exec()){
        QMessageBox::information(this, "AVISO", "Registro excluido");                     // Selecionando linha e removendo. :( Bugado ainda.
          ui->tabela->removeRow(linha);                                                   // Está fechando ao clicar sem nada na tabela.
      }else{
        QMessageBox::warning(this, "ERRO", "Erro ao excluir registro");
      }
}

void Principal::on_actionSalvar_3_triggered()
{
  QString nome_arquivo = QFileDialog::getSaveFileName(this,
                                                         "Salvar Arquivo",
                                                         "",
                                                         "*.csv");
    empresa.salvarDados(nome_arquivo);  // Salvando Arquivos.
}

void Principal::on_actionCarregar_triggered()
{
  QString nome_arquivo = QFileDialog::getOpenFileName(this,
                                                           "Abrir arquivo",
                                                           "",
                                                           "CSV(*.csv)");
       empresa.carregarDados(nome_arquivo);
       for(int i = 0; i<empresa.size();i++){
           ui->tabela->insertRow(i);
           ui->tabela->setItem(i,0,new QTableWidgetItem(empresa[i].getNom()));
           ui->tabela->setItem(i,1,new QTableWidgetItem(empresa[i].getEnd()));
           ui->tabela->setItem(i,2,new QTableWidgetItem(empresa[i].getCpf()));
           ui->tabela->setItem(i,3,new QTableWidgetItem(empresa[i].getIdentidade()));
           ui->tabela->setItem(i,4,new QTableWidgetItem(empresa[i].getSetor()));
           ui->tabela->setItem(i,5,new QTableWidgetItem(empresa[i].getID()));
           ui->tabela->setItem(i,6,new QTableWidgetItem(empresa[i].getSalario()));
       }
}

void Principal::carregar(){
     ui->tabela->clearContents();

     QString nomeArquivo = QFileDialog::getOpenFileName(this,"Testando","","CSV(*csv)");
     empresa.carregarDados(nomeArquivo);
     for(int i=0;i<empresa.size();i++){
         ui->tabela->insertRow(i);
         (empresa[i],i);
}}

void Principal::on_tabela_cellDoubleClicked(int row, int column)
{
    if (column == 0){
        bool ok;
        QString nome = QInputDialog::getText(this, "Editar Nome", "Escreva o novo nome", QLineEdit::Normal, "", &ok);

        if(ok && !nome.isEmpty()){
            empresa.editarNome(row, nome);
            inserirNaTabela(empresa[row],row);
          }
      }

    if (column == 1){
        bool ok;
        QString end = QInputDialog::getText(this, "Editar Endereço", "Escreva o novo endereço", QLineEdit::Normal, "", &ok);

        if(ok && !end.isEmpty()){
            empresa.editarEnd(row, end);
            inserirNaTabela(empresa[row],row);
          }
      }
    if (column == 2){
        bool ok;
        QString cpf = QInputDialog::getText(this, "Editar CPF", "Informe novo CPF:", QLineEdit::Normal, "", &ok);

        if(ok && !cpf.isEmpty()){
            empresa.editarCPF(row, cpf);
            inserirNaTabela(empresa[row],row);
          }
      }
    if (column == 3){
        bool ok;
        QString rg = QInputDialog::getText(this, "Editar identidade", "Informe RG:", QLineEdit::Normal, "", &ok);

        if(ok && !rg.isEmpty()){
            empresa.editarRG(row, rg);
            inserirNaTabela(empresa[row],row);
          }
      }
    if (column == 4){
        bool ok;
        QString set = QInputDialog::getText(this, "Editar setor", "Informe o novo setor", QLineEdit::Normal, "", &ok);

        if(ok && !set.isEmpty()){
            empresa.editarSetor(row, set);
            inserirNaTabela(empresa[row],row);
          }
      }
    if (column == 5){
        bool ok;
        QString us = QInputDialog::getText(this, "Editar Usuário", "Escreva o novo usuário", QLineEdit::Normal, "", &ok);

        if(ok && !us.isEmpty()){
            empresa.editarUsu(row, us);
            inserirNaTabela(empresa[row],row);
          }
      }
    if (column == 6){
        bool ok;
        QString slr = QInputDialog::getText(this, "Editar Salário", "Atualiza o salário", QLineEdit::Normal, "", &ok);

        if(ok && !slr.isEmpty()){
            empresa.editarSal(row, slr.toFloat());
            inserirNaTabela(empresa[row],row);
          }
      }
}
