/*
 * Matriz.hpp
 *
 *  Created on: Sep 6, 2015
 *      Author: cesar
 */

#ifndef MATRIZ_HPP_
#define MATRIZ_HPP_

template<typename type, unsigned rows, unsigned cols>
struct Matriz {
	type me[rows][cols];
	Matriz() {}
	Matriz(type const (& matriz)[rows][cols])
	{
		(*this) = matriz;
	}
	inline Matriz<type,rows,cols> & operator=(type const (& matriz)[rows][cols])
	{
		for(unsigned row = 0; row < rows; row++)
		{
			for(unsigned col = 0; col < cols; col++)
			{
				(*this)(row,col) = matriz[row][col];
			}
		}
		return *this;
	}
	inline type & operator()(unsigned const row, unsigned const col)
	{
		return this->me[row][col];
	}
	inline Matriz<type,rows,cols> & operator+=(Matriz<type,rows,cols> const & matriz)
	{
		return (*this) = (*this)+matriz;
	}
	inline Matriz<type,rows,cols> & operator-=(Matriz<type,rows,cols> const & matriz)
	{
		return (*this) = (*this)-matriz;
	}
	inline Matriz<type,rows,cols> & operator*=(Matriz<type,cols,cols> const & matriz)
	{
		return (*this) = (*this)*matriz;
	}
	inline Matriz<type,rows,cols> & operator*=(type const & constante)
	{
		return (*this) = (*this)*constante;
	}
	inline Matriz<type,rows,cols> & operator/=(type const & constante)
	{
		return (*this) = (*this)/constante;
	}
	//const
	inline type operator()(unsigned const row, unsigned const col) const
	{
		// return (*this)(row,col); // looping
		return this->me[row][col];
	}
	inline Matriz<type,rows,cols> operator*(type const & constante) const
	{
		return operatorProduto<multiplicacao>(constante);
	}
	inline Matriz<type,rows,cols> operator/(type const & constante) const
	{
		return operatorProduto<divisao>(constante);
	}
	inline Matriz<type,rows,cols> operator+(Matriz<type,rows,cols> const & matriz) const
	{
		return operatorSoma<adicao>(matriz);
	}
	inline Matriz<type,rows,cols> operator-(Matriz<type,rows,cols> const & matriz) const
	{
		return operatorSoma<subtracao>(matriz);
	}
	template<unsigned new_cols>
	inline Matriz<type,rows,new_cols> operator*(Matriz<type,cols,new_cols> const & matriz) const
	{
		Matriz<type,rows,new_cols> result;
		for(unsigned row = 0; row < rows; row++)
		{
			for(unsigned col = 0; col < new_cols; col++)
			{
				result(row,col) = 0;
				for(unsigned aux = 0; aux < cols; aux++)
				{
					result(row,col) += (*this)(row,aux) * matriz(aux,col);
				}
			}
		}
		return result;
	}
protected:
	enum soma {adicao, subtracao};
	template<soma operador>
	inline Matriz<type,rows,cols> operatorSoma(Matriz<type,rows,cols> const & matriz) const
	{
		Matriz<type,rows,cols> result;
		for(unsigned row = 0; row < rows; row++)
		{
			for(unsigned col = 0; col < cols; col++)
			{
				switch (operador) {
					case adicao:	result(row,col) = (*this)(row,col) + matriz(row,col);
						break;
					case subtracao:	result(row,col) = (*this)(row,col) - matriz(row,col);
						break;
				}
			}
		}
		return result;
	}
	enum produto {multiplicacao, divisao};
	template<produto operador>
	inline Matriz<type,rows,cols> operatorProduto(type const & constante) const
	{
		Matriz<type,rows,cols> result;
		for(unsigned row = 0; row < rows; row++)
		{
			for(unsigned col = 0; col < cols; col++)
			{
				switch (operador) {
					case multiplicacao:	result(row,col) = (*this)(row,col) * constante;
						break;
					case divisao:		result(row,col) = (*this)(row,col) / constante;
						break;
				}
			}
		}
		return result;
	}
};

#endif /* MATRIZ_HPP_ */
