#include "empresa.h"

void Empresa::incluirFuncionario(Funcionario a)
{
    empresa.push_back(a);
}

Empresa::Empresa()
{

}

void Empresa::salvarDados(QString nomeDoArquivo)
{
    QFile arquivo(nomeDoArquivo);

    arquivo.open(QIODevice::WriteOnly);

    QString linha;
    for (auto a : empresa){
        linha = a.getNom() + "," + a.getCpf() + "," + a.getEnd() + "," +a.getIdentidade()+ "," +a.getSetor()+ "," +a.getID()+ "," +a.getPW()+ ","+a.getSalario()+" \n";
        arquivo.write(linha.toLocal8Bit());
    }

    arquivo.close();
}

bool Empresa::carregarDados(QString arquivo)
{
     QFile file(arquivo);
     if(!file.open(QIODevice::ReadOnly))
         return false;

     QString linha;
     Funcionario a;
     while(!file.atEnd()){
         linha = file.readLine();
         QStringList dados = linha.split(",");
         a.setNom(dados[0]);
         a.setEnd(dados[1]);
         a.setCpf(dados[2]);
         a.setIdentidade(dados[3]);
         a.setSetor(dados[4]);
         a.setID(dados[5]);
         a.setSalario(dados[6].toFloat());
         incluirFuncionario(a);
     }
     file.close();
     return true;
}

float Empresa::maiorSalario()
{
  Funcionario *maior;
      maior = std::max_element(empresa.begin(),empresa.end(),compararPorSalario);
     return maior->getSalario();
}

float Empresa::menorSalario()
{
  Funcionario *menor;
      menor = std::min_element(empresa.begin(),empresa.end(),compararPorSalario);
      return menor ->getSalario();
}

float Empresa::mediaDeSalario()
{
  float media=0;
      for(Funcionario a : empresa){
        media+=a.getSalario();
      }
      return media/empresa.size();
}

void Empresa::ordenar()
{
 std::sort(empresa.begin(),empresa.end(),compararPorNome);
}

void Empresa::ordenar2()
{
 std::sort(empresa.begin(),empresa.end(),compararPorSalario);
}

bool compararPorNome(Funcionario a, Funcionario b)
{
    return a.getNom() <  b.getNom();
}
int Empresa::size()
{
    return empresa.size();
}

Funcionario Empresa::operator[](int indice)
{
    return empresa[indice];
}

bool compararPorSalario(Funcionario a, Funcionario b)
{
  return a.getSalario() < b.getSalario();
}

void Empresa::editarNome(int i, QString EdNom){
  empresa[i].setNom(EdNom);
}

void Empresa::editarEnd(int i, QString end)
{
  empresa[i].setEnd(end);
}

void Empresa::editarCPF(int i, QString cpf)
{
  empresa[i].setCpf(cpf);
}
void Empresa::editarRG(int i, QString rg){
  empresa[i].setIdentidade(rg);
}
void Empresa::editarSetor(int i, QString setor){
  empresa[i].setSetor(setor);
}
void Empresa::editarUsu(int i, QString usu){
  empresa[i].setID(usu);
}
void Empresa::editarSal(int i, float salario){
  empresa[i].setSalario(salario);
}
