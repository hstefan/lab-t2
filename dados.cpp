#include "dados.h"

namespace base
{

	Aluno::Aluno(const Curso* curso, unsigned int matricula, const std::string& nome)
		: curso(curso), matricula(matricula), nome(nome) 
	{}

	const Curso& Aluno::getCurso() const
	{ 
		return *curso; 
	}

	unsigned int Aluno::getMatricula() const
	{ 
		return matricula; 
	}

	const std::string& Aluno::getNome() const
	{ 
		return nome; 
	}

	void Aluno::setCurso(const Curso* curso)
	{
		this->curso = curso;
	}

	void Aluno::setMatricula(unsigned int matricula)
	{
		this->matricula = matricula;
	}

	void Aluno::setNome(const std::string& nome)
	{
		this->nome = nome;
	}

	Professor::Professor(const std::string& siape, const std::string& nome, 
		const std::string& area, const std::string& titulacao)
		: siape(siape), nome(nome), area(area), titulacao(titulacao)
	{}

	void Professor::setSiape(const std::string& siape)
	{
		this->siape = siape;
	}

	void Professor::setNome(const std::string& nome)
	{
		this->nome = nome;
	}

	void Professor::setArea(const std::string& area)
	{
		this->area = area;
	}

	void Professor::setTitulacao(const std::string& titulacao)
	{
		this->titulacao = titulacao;
	}

	const std::string& Professor::getSiape() const
	{
		return siape;
	}

	const std::string& Professor::getNome() const
	{
		return nome;
	}

	const std::string& Professor::getArea() const
	{
		return area;
	}

	const std::string& Professor::getTitulacao() const
	{
		return titulacao;
	}

	Disciplina::Disciplina(const std::string& codigo, Curso* curso, const std::string& nome, 
			unsigned int carga, ds::list<Disciplina>& requisitos)
		: codigo(codigo), curso(curso), nome(nome), carga(carga), requisitos()
	{
		for(ds::list<Disciplina>::iterator it = requisitos.begin(); it != requisitos.end(); it++)
		{
			this->requisitos.push_back(&*it);
		}
	}
	
	void Disciplina::setCodigo(const std::string& codigo)
	{
		this->codigo = codigo;
	}

	void Disciplina::setCurso(const Curso* curso)
	{
		this->curso = curso;
	}

	void Disciplina::setNome(const std::string& nome)
	{
		this->nome = nome;
	}

	void Disciplina::setCarga(unsigned int carga)
	{
		this->carga = carga;
	}

	template <class InputIterator>
	void Disciplina::setRequisitos(InputIterator begin, InputIterator end)
	{
		requisitos.clear();
		while(begin != end)
		{
			requisitos.push_back(*begin);
			begin++;
		}
	}

	const std::string& Disciplina::getCodigo() const
	{
		return codigo;
	}

	const Curso& Disciplina::getCurso() const
	{
		return *curso;
	}

	const std::string& Disciplina::getNome() const
	{
		return nome;
	}

	unsigned int Disciplina::getCarga() const
	{
		return carga;
	}

	Disciplina::DiscIterator Disciplina::getRequisitosBeginIter()
	{
		return requisitos.begin();
	}

	Disciplina::DiscIterator Disciplina::getRequisitosEndIter()
	{
		return requisitos.end();
	}

	void Disciplina::adcionaRequisito(const Disciplina* disciplina)
	{
		requisitos.push_back(disciplina);
	}

	void Disciplina::removeRequisito(const Disciplina* disciplina)
	{
		for(DiscIterator it = requisitos.begin(); it != requisitos.end(); it++)
		{
			if(*it = disciplina)
			{
				removeRequisito(it);
				break;
			}
		}
	}

	void Disciplina::removeRequisito(DiscIterator disciplina)
	{
		requisitos.erase(disciplina);
	}
}