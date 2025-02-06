/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 23:45:31 by tbabou            #+#    #+#             */
/*   Updated: 2025/02/06 23:45:31 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
    Harl cry_baby;

    cry_baby.complain("DEBUG");
    cry_baby.complain("INFO");
    cry_baby.complain("WARNING");
    cry_baby.complain("ERROR");
    cry_baby.complain("FATAL");
    return (0);
}