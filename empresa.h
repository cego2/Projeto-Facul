#ifndef EMPRESA_H
#define EMPRESA_H
#include <QFile>
#include "funcionario.h"
#include <QVector>
#include <QObject>
class Empresa
{
private:
  QVector <Funcionario> empresa;
public:
  Funcionario operator[](int indice);
  void incluirFuncionario(Funcionario a);
  float maiorSalario();
  float menorSalario();
  float mediaDeSalario();
  void ordenar();
  void ordenar2();
  int size();
  Empresa();
  void editarNome(int i, QString EdNom);
  void editarEnd(int i, QString end);
  void editarCPF(int i, QString cpf);
  void editarRG(int i, QString rg);
  void editarSetor(int i, QString setor);
  void editarUsu(int i, QString usu);
  void editarSal(int i, float salario);
  bool carregarDados(QString arquivo);
  void salvarDados(QString nomeDoArquivo);
};
bool compararPorNome(Funcionario a, Funcionario b);
bool compararPorSalario(Funcionario a, Funcionario b);

#endif // EMPRESA_H
