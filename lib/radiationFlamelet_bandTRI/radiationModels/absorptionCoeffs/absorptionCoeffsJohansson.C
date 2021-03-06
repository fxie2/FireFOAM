/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2011 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/

#include "absorptionCoeffsJohansson.H"
#include "IOstreams.H"

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::radiation::absorptionCoeffsJohanssen::absorptionCoeffsJohanssen(Istream& is)
:
   Tcommon_(readScalar(is)),
   Tlow_(readScalar(is)),
   Thigh_(readScalar(is)),
   invTemp_(readBool(is))
{
    for (label coefLabel=0; absorptionCoeffsJohanssen::nCoeffs_; coefLabel++)
    {
        is >> highACoeffs_[coefLabel];
    }

    for (label coefLabel=0; absorptionCoeffsJohanssen::nCoeffs_; coefLabel++)
    {
        is >> lowACoeffs_[coefLabel];
    }
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * //

Foam::radiation::absorptionCoeffsJohanssen::~absorptionCoeffsJohanssen()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void Foam::radiation::absorptionCoeffsJohanssen::checkT(const scalar T) const
{
    if (T < Tlow_ || T > Thigh_)
    {
        WarningIn
        (
            "absorptionCoeffsJohanssen::checkT(const scalar T) const"
        )   << "usinf absCoeff out of temperature range:" << nl
            << "    " << Tlow_ << " -> " << Thigh_ << ";  T = " << T
            << nl << endl;
    }
}


const Foam::radiation::absorptionCoeffsJohanssen::coeffArray&
Foam::radiation::absorptionCoeffsJohanssen::coeffs
(
    const scalar T
) const
{
    checkT(T);

    if (T < Tcommon_)
    {
        return lowACoeffs_;
    }
    else
    {
        return highACoeffs_;
    }
}


void Foam::radiation::absorptionCoeffsJohanssen::initialise(Istream&)
{
    absorptionCoeffsJohanssen(Istream);
}


void Foam::radiation::absorptionCoeffsJohanssen::initialise(const dictionary& dict)
{
    dict.lookup("Tcommon") >> Tcommon_;
    dict.lookup("Tlow") >> Tlow_;
    dict.lookup("Thigh") >> Thigh_;
    dict.lookup("invTemp") >> invTemp_;

    dict.lookup("loTcoeffs") >> lowACoeffs_;
    dict.lookup("hiTcoeffs") >> highACoeffs_;
}


// ************************************************************************* //
