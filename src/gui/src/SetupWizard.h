/*
 * synergy -- mouse and keyboard sharing utility
 * Copyright (C) 2012-2016 Symless Ltd.
 * 
 * This package is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * found in the file LICENSE that should have accompanied this file.
 * 
 * This package is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "ui_SetupWizardBase.h"
#include "SynergyLocale.h"
#include "PluginWizardPage.h"

#include <QWizard>
#include <QNetworkAccessManager>

class MainWindow;

class SetupWizard : public QWizard, public Ui::SetupWizardBase
{
	Q_OBJECT
public:
	enum {
		kMaximiumLoginAttemps = 3
	};

public:
	SetupWizard(MainWindow& mainWindow, bool startMain);
	virtual ~SetupWizard();
	bool validateCurrentPage();

protected:
	void changeEvent(QEvent* event);
	void accept();
	void reject();
	void notifyActivation(QString identity);

private:
	MainWindow& m_MainWindow;
	bool m_StartMain;
	SynergyLocale m_Locale;
	int m_Edition;
	PluginWizardPage* m_pPluginPage;
	int m_LoginAttemps;

private slots:
	void on_m_pRadioButtonSubscription_toggled(bool checked);
	void on_m_pRadioButtonActivate_toggled(bool checked);
	void on_m_pRadioButtonSkip_toggled(bool checked);
	void on_m_pComboLanguage_currentIndexChanged(int index);
};
