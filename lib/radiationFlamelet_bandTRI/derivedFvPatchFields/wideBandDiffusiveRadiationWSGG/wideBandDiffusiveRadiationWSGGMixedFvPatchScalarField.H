/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2011-2012 OpenFOAM Foundation
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

Class
    Foam::radiation::wideBandDiffusiveRadiationWSGGMixedFvPatchScalarField

Group
    grpThermoBoundaryConditions

Description
    This boundary condition provides a wide-band, diffusive radiation
    condition, where the patch temperature is specified.

    \heading Patch usage

    \table
        Property     | Description             | Required    | Default value
        T            | temperature field name  | no          | T
    \endtable

    Example of the boundary condition specification:
    \verbatim
    myPatch
    {
        type            wideBandDiffusiveRadiationWSGG;
        value           uniform 0;
    }
    \endverbatim

SeeAlso
    Foam::mixedFvPatchScalarField
    Foam::radiationCoupledBase

SourceFiles
    wideBandDiffusiveRadiationWSGGMixedFvPatchScalarField.C

\*---------------------------------------------------------------------------*/

#ifndef wideBandDiffusiveRadiationWSGGMixedFvPatchScalarField_H
#define wideBandDiffusiveRadiationWSGGMixedFvPatchScalarField_H

#include "mixedFvPatchFields.H"
#include "radiationCoupledBase.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace radiation
{
/*---------------------------------------------------------------------------*\
      Class wideBandDiffusiveRadiationWSGGMixedFvPatchScalarField Declaration
\*---------------------------------------------------------------------------*/

class wideBandDiffusiveRadiationWSGGMixedFvPatchScalarField
:
    public mixedFvPatchScalarField,
    public radiationCoupledBase
{
    // Private data

        //- Name of temperature field
        word TName_;


public:

    //- Runtime type information
    TypeName("wideBandDiffusiveRadiationWSGG");


    // Constructors

        //- Construct from patch and internal field
        wideBandDiffusiveRadiationWSGGMixedFvPatchScalarField
        (
            const fvPatch&,
            const DimensionedField<scalar, volMesh>&
        );

        //- Construct from patch, internal field and dictionary
        wideBandDiffusiveRadiationWSGGMixedFvPatchScalarField
        (
            const fvPatch&,
            const DimensionedField<scalar, volMesh>&,
            const dictionary&
        );

        //- Construct by mapping given GreyDiffusiveRadiationMixedFvPatchField
        //  onto a new patch
        wideBandDiffusiveRadiationWSGGMixedFvPatchScalarField
        (
            const wideBandDiffusiveRadiationWSGGMixedFvPatchScalarField&,
            const fvPatch&,
            const DimensionedField<scalar, volMesh>&,
            const fvPatchFieldMapper&
        );

        //- Construct as copy
        wideBandDiffusiveRadiationWSGGMixedFvPatchScalarField
        (
            const wideBandDiffusiveRadiationWSGGMixedFvPatchScalarField&
        );

        //- Construct and return a clone
        virtual tmp<fvPatchScalarField> clone() const
        {
            return tmp<fvPatchScalarField>
            (
                new wideBandDiffusiveRadiationWSGGMixedFvPatchScalarField(*this)
            );
        }

        //- Construct as copy setting internal field reference
        wideBandDiffusiveRadiationWSGGMixedFvPatchScalarField
        (
            const wideBandDiffusiveRadiationWSGGMixedFvPatchScalarField&,
            const DimensionedField<scalar, volMesh>&
        );

        //- Construct and return a clone setting internal field reference
        virtual tmp<fvPatchScalarField> clone
        (
            const DimensionedField<scalar, volMesh>& iF
        ) const
        {
            return tmp<fvPatchScalarField>
            (
                new wideBandDiffusiveRadiationWSGGMixedFvPatchScalarField(*this, iF)
            );
        }


    // Member functions

        // Access

            //- Return the temperature field name
            const word& TName() const
            {
                return TName_;
            }

            //- Return reference to the temperature field name to allow
            //  adjustment
            word& TName()
            {
                return TName_;
            }


        // Evaluation functions

            //- Update the coefficients associated with the patch field
            virtual void updateCoeffs();


        // I-O

            //- Write
            virtual void write(Ostream&) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
