//
// Copyright (C) 2013-2018 University of Amsterdam
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public
// License along with this program.  If not, see
// <http://www.gnu.org/licenses/>.
//

#ifndef LISTMODELINTERACTIONASSIGNED_H
#define LISTMODELINTERACTIONASSIGNED_H

#include "listmodelassignedinterface.h"
#include "listmodelavailableinterface.h"
#include "interactionmodel.h"
#include "analysis/options/options.h"
#include "analysis/options/optionterm.h"

class ListModelInteractionAssigned : public ListModelAssignedInterface, public InteractionModel
{
	Q_OBJECT
	
public:
	ListModelInteractionAssigned(QMLListView* listView, bool mustContainLowerTerms);

	void			initTerms(const Terms &terms, const RowControlsOptions& = RowControlsOptions())	override;
	void			setAvailableModel(ListModelAvailableInterface *source)							override;
	Terms			termsFromIndexes(const QList<int> &indexes)								const	override;
	Terms			canAddTerms(const Terms& terms) const override;
	Terms			addTerms(const Terms& terms, int dropItemIndex = -1, JASPControlBase::AssignType assignType = JASPControlBase::AssignType::AssignDefault) override;
	void			moveTerms(const QList<int>& indexes, int dropItemIndex = -1)					override;
	void			removeTerms(const QList<int> &indices)											override;
	QString			getItemType(const Term &term)											const	override;
	const Terms&	terms(const QString& what = QString())									const	override;

		
public slots:
	void availableTermsChanged(const Terms* termsToAdd, const Terms* termsToRemove) override;
	
protected:
	void addCombinedTerms(const Terms& terms, JASPControlBase::AssignType assignType);
	void _addTerms(const Terms& terms, bool combineWithExistingTerms);
	
	void setTerms();
};


#endif // LISTMODELINTERACTIONASSIGNED_H
