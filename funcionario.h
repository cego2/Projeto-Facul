#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <QString>

class Funcionario
{
private:
  QString nom;
  QString setor;
  QString cpf;
  QString identidade;
  QString end;
  QString ID;
  QString PW;
  float salario;
public:
  Funcionario();
  void setNom(const QString &value);
  QString getNom() const;
  void setSetor(const QString &value);
  QString getSetor() const;
  void setCpf(const QString &value);
  QString getCpf() const;
  void setIdentidade(const QString &value);
  QString getIdentidade() const;
  void setEnd(const QString &value);
  QString getEnd() const;
  void setID(const QString &value);
  QString getID() const;
  void setPW(const QString &value);
  QString getPW() const;
  void setSalario(float value);
  float getSalario() const;
};

#endif // FUNCIONARIO_H
