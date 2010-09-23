#ifndef HUGO_DATA_H__
#define HUGO_DATA_H__

#include <string>
#include "secondary_data.h"
#include "list.h"
#include "registro.h"

namespace base
{
	class Aluno;
	class Professor;
	class Disciplina;
	class Turma;
	class Avaliacao;
	class Curso;

	class Aluno : public data::Registro
	{
	public:
		Aluno(const Curso* curso, unsigned int matricula, const std::string& nome);

		const Curso& getCurso() const;
		unsigned int getMatricula() const;
		const std::string& getNome() const;
		void setCurso(const Curso* curso);
		void setMatricula(unsigned int matricula);
		void setNome(const std::string& nome);

		virtual void save();
		virtual void erase();
		virtual void sync();
	private:
		const Curso* curso;
		unsigned int matricula;
		std::string nome;
	};

	class Professor : public data::Registro
	{
	public:
		Professor(const std::string& siape, const std::string& nome, const std::string& area, const std::string& titulacao);
		
		void setSiape(const std::string& siape);
		void setNome(const std::string& nome);
		void setArea(const std::string& area);
		void setTitulacao(const std::string& titulacao);
		const std::string& getSiape() const;
		const std::string& getNome() const;
		const std::string& getArea() const;
		const std::string& getTitulacao() const;

		virtual void save();
		virtual void erase();
		virtual void sync();
	private:
		std::string siape;
		std::string nome;
		std::string area;
		std::string titulacao;
	};

	class Disciplina : public data::Registro
	{
	public:
		typedef ds::list<const Disciplina*>::iterator DiscIterator;

		Disciplina(const std::string& codigo, Curso* curso, const std::string& nome, 
			unsigned int carga, ds::list<Disciplina>& requisitos = ds::list<Disciplina>());

		void setCodigo(const std::string& codigo);
		void setCurso(const Curso* curso);
		void setNome(const std::string& nome);
		void setCarga(unsigned int carga);
		
		template <class InputIterator>
		  void setRequisitos(InputIterator begin, InputIterator end);
		
		const std::string& getCodigo() const;
		const Curso& getCurso() const;
		const std::string& getNome() const;
		unsigned int getCarga() const;
		DiscIterator getRequisitosBeginIter();
		DiscIterator getRequisitosEndIter();

		void adcionaRequisito(const Disciplina* disciplina);
		void removeRequisito(const Disciplina* disciplina);
		void removeRequisito(const DiscIterator disciplina);

		virtual void save();
		virtual void erase();
		virtual void sync();
	private:
		std::string codigo;
		const Curso* curso;
		std::string nome;
		unsigned int carga;
		ds::list<const Disciplina*> requisitos; 
	};

	class Turma : public data::Registro
	{
	public:
		typedef ds::list<Aluno*>::iterator AlunosIter;
		typedef ds::list<Professor*>::iterator ProfessoresIter;
		
		Turma(const Curso* curso, ds::list<Aluno>& alunos, ds::list<Professor>& professores);

		AlunosIter getAlunosBegin();
		AlunosIter getAlunosEnd();
		ProfessoresIter getProfessoresBegin();
		ProfessoresIter getProfessoresEnd();
		const Curso&  getCurso();

		template <class InputIterator>
		  void setAlunos(InputIterator begin, InputIterator end);

		template <class InputIterator>
		  void setProfessores(InputIterator begin, InputIterator end);

		void setCurso(const Curso* curso);

		void adcionaAluno(Aluno* aluno);
		void adcionaProfessor(Professor* professor);
		void removerAluno(AlunosIter aluno);
		void removerProfessor(ProfessoresIter professor);

		virtual void save();
		virtual void erase();
		virtual void sync();

	private:
		ds::list<Aluno*> alunos;
		ds::list<Professor*> professores;
		const Curso* curso;
	};

	class Curso : public data::Registro
	{
	public:

		Curso(const std::string& codigo, const std::string& nome, ds::list<Turma>& turmas
			= ds::list<Turma>()); 
		typedef ds::list<Turma*>::iterator TurmasIter;

		const std::string& getCodigo() const;
		const std::string& getNome() const;
		TurmasIter getTurmasBegin();
		TurmasIter getTurmasEnd();
		
		void setCodigo(const std::string& codigo);
		void setNome(const std::string& nome);
		template <class InputIterator>
		  void setTurmas(InputIterator begin, InputIterator end);

		void adcionaTurma(Turma* const turma);
		void removeTurma(TurmasIter turma);
		virtual void save();
		virtual void erase();
		virtual void sync();
	private:
		std::string codigo;
		std::string nome;
		ds::list<Turma*> turmas;
	};
}

#endif