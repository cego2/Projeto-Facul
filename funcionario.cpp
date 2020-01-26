#include "funcionario.h"

void Funcionario::setNom(const QString &value)
{
  if(value.size() >= 3){
          nom = value;}
}

QString Funcionario::getNom() const
{
  return nom;
}

void Funcionario::setSetor(const QString &value)
{
  if(value.size() >= 3){
  setor = value;}
}

QString Funcionario::getSetor() const
{
  return setor;
}

void Funcionario::setCpf(const QString &value)
{
  if(value.size() == 11){
  cpf = value;}
}

QString Funcionario::getCpf() const
{
  return cpf;
}

void Funcionario::setIdentidade(const QString &value)
{
  if(value.size() >= 7){
  identidade = value;}
}

QString Funcionario::getIdentidade() const
{
  return identidade;
}

void Funcionario::setEnd(const QString &value)
{
  if(value != ""){
  end = value;}
}

QString Funcionario::getEnd() const
{
  return end;
}

void Funcionario::setID(const QString &value)
{
  if(value.size() == 4){
  ID = value;}
}

QString Funcionario::getID() const
{
  return ID;
}

void Funcionario::setPW(const QString &value)
{
  if(value.size() >= 4 && value.size() <= 10){
    PW = value;}
}

QString Funcionario::getPW() const
{
  return PW;
}


void Funcionario::setSalario(float value)
{
  salario = value;
}

float Funcionario::getSalario() const
{
  return salario;
}

Funcionario::Funcionario()
{

}
