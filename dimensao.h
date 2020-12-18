#ifndef DIMENSAO_H
#define DIMENSAO_H

#include <QDialog>

namespace Ui {
class Dimensao;
}
/**
 * @brief The Dimensao class
 * Classe criada para captar o tamanho da matriz de desenho. A ação é feita através de uma caixa de diálogo.
 */
class Dimensao : public QDialog
{
    Q_OBJECT

public:
    explicit Dimensao(QWidget *parent = nullptr);
    ~Dimensao();
    /**
     * @brief Função membro que retorna o valor da dimensão x da matriz de desenho
     */
    int getX();
    /**
     * @brief Função membro que retorna o valor da dimensão y da matriz de desenho
     */
    int getY();
    /**
     * @brief Função membro que retorna o valor da dimensão z da matriz de desenho
     */
    int getZ();

private:
    Ui::Dimensao *ui;
};

#endif // DIMENSAO_H
