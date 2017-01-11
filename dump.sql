-- phpMyAdmin SQL Dump
-- version 4.4.13.1deb1
-- http://www.phpmyadmin.net
--
-- Client :  localhost
-- Généré le :  Lun 09 Janvier 2017 à 19:55
-- Version du serveur :  5.6.31-0ubuntu0.15.10.1
-- Version de PHP :  5.6.23-1+deprecated+dontuse+deb.sury.org~wily+1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `timetable`
--

-- --------------------------------------------------------

--
-- Structure de la table `cours`
--

CREATE TABLE IF NOT EXISTS `cours` (
  `id` int(11) NOT NULL,
  `libelle` varchar(100) NOT NULL,
  `id_filiere` int(11) NOT NULL,
  `id_enseignant` int(11) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;

--
-- Contenu de la table `cours`
--

INSERT INTO `cours` (`id`, `libelle`, `id_filiere`, `id_enseignant`) VALUES
(1, 'POO', 1, 3),
(2, 'Finance', 1, 1),
(3, 'Comptabilité', 1, 2),
(4, 'POO', 3, 1);

-- --------------------------------------------------------

--
-- Structure de la table `enseignants`
--

CREATE TABLE IF NOT EXISTS `enseignants` (
  `id` int(11) NOT NULL,
  `nom` varchar(20) NOT NULL,
  `prenom` varchar(20) NOT NULL,
  `specialite` varchar(60) DEFAULT NULL,
  `adresse` text,
  `telephone` varchar(15) NOT NULL,
  `mail` varchar(30) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8;

--
-- Contenu de la table `enseignants`
--

INSERT INTO `enseignants` (`id`, `nom`, `prenom`, `specialite`, `adresse`, `telephone`, `mail`) VALUES
(1, 'TALAI', 'Younes', 'Finance', '4 rue Charle Keller 54000 Nancy', '0125665666', 'talai@gmail.com'),
(2, 'ALAMI', 'ANAS', 'Comptabilité', '20 Rue des varcanes 36000 Nantes', '020565656', 'alami@gmail.com'),
(3, 'Bangi', 'pière', 'POO', 'Rue Tilila No 1 Agadir Maroc', '0515815015', 'bangi@gmail.com'),
(5, 'Kolon', 'Pière', 'Réseaux', '15 avenue marchal 57000 Metz', '6005621022', 'kolon@gmail.com');

-- --------------------------------------------------------

--
-- Structure de la table `etudiants`
--

CREATE TABLE IF NOT EXISTS `etudiants` (
  `id` int(11) NOT NULL,
  `nom` varchar(20) NOT NULL,
  `prenom` varchar(20) NOT NULL,
  `adresse` text NOT NULL,
  `telephone` varchar(60) DEFAULT NULL,
  `mail` varchar(60) NOT NULL,
  `id_filiere` int(11) NOT NULL,
  `id_niveau` int(11) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8;

--
-- Contenu de la table `etudiants`
--

INSERT INTO `etudiants` (`id`, `nom`, `prenom`, `adresse`, `telephone`, `mail`, `id_filiere`, `id_niveau`) VALUES
(1, 'Anas', 'lami', 'zazazaz', '02021021501', 'zaz@dhd.com', 1, 1),
(2, 'Madona', 'marie', '14 rue place carnot Nancy', '0202052000', 'bbbb@gmail.com', 1, 1),
(3, 'pool', 'ila', '18 rue marina 54 000 Nancy', '0202052000', 'pool@gmail.com', 1, 1);

-- --------------------------------------------------------

--
-- Structure de la table `filieres`
--

CREATE TABLE IF NOT EXISTS `filieres` (
  `id` int(11) NOT NULL,
  `libelle` varchar(100) NOT NULL,
  `id_niveau` int(11) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8;

--
-- Contenu de la table `filieres`
--

INSERT INTO `filieres` (`id`, `libelle`, `id_niveau`) VALUES
(1, 'MIAGE', 1),
(2, 'INFO', 1),
(3, 'INFO', 2),
(4, 'InfoGraphie', 1),
(5, 'Tourisme', 5);

-- --------------------------------------------------------

--
-- Structure de la table `niveaux`
--

CREATE TABLE IF NOT EXISTS `niveaux` (
  `id` int(11) NOT NULL,
  `libelle` varchar(100) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8;

--
-- Contenu de la table `niveaux`
--

INSERT INTO `niveaux` (`id`, `libelle`) VALUES
(1, 'Licence 1'),
(2, 'Licence 2'),
(3, 'Licence 3'),
(4, 'Master 1'),
(5, 'Master 2');

-- --------------------------------------------------------

--
-- Structure de la table `niveaux_filieres`
--

CREATE TABLE IF NOT EXISTS `niveaux_filieres` (
  `id_niveau` int(11) NOT NULL,
  `id_filiere` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Contenu de la table `niveaux_filieres`
--

INSERT INTO `niveaux_filieres` (`id_niveau`, `id_filiere`) VALUES
(1, 1),
(2, 1),
(3, 1),
(4, 1),
(5, 1);

-- --------------------------------------------------------

--
-- Structure de la table `salles`
--

CREATE TABLE IF NOT EXISTS `salles` (
  `id` int(11) NOT NULL,
  `numero` int(11) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8;

--
-- Contenu de la table `salles`
--

INSERT INTO `salles` (`id`, `numero`) VALUES
(1, 100),
(2, 102),
(3, 107),
(4, 37),
(5, 90),
(6, 39),
(7, 7),
(8, 8),
(9, 9),
(10, 10);

-- --------------------------------------------------------

--
-- Structure de la table `seances`
--

CREATE TABLE IF NOT EXISTS `seances` (
  `id` int(11) NOT NULL,
  `date_seance` date NOT NULL,
  `heure_debut` time NOT NULL,
  `heure_fin` time NOT NULL,
  `id_cours` int(11) NOT NULL,
  `id_salle` int(11) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8;

--
-- Contenu de la table `seances`
--

INSERT INTO `seances` (`id`, `date_seance`, `heure_debut`, `heure_fin`, `id_cours`, `id_salle`) VALUES
(1, '2016-09-01', '08:00:00', '10:00:00', 1, 4),
(2, '2016-09-01', '10:15:00', '12:15:00', 2, 3),
(3, '2016-09-01', '14:00:00', '18:00:00', 1, 1),
(4, '2016-09-02', '08:00:00', '10:00:00', 1, 6),
(5, '2016-09-02', '13:00:00', '17:00:00', 3, 4),
(6, '2016-09-03', '09:00:00', '12:00:00', 2, 2);

--
-- Index pour les tables exportées
--

--
-- Index pour la table `cours`
--
ALTER TABLE `cours`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `enseignants`
--
ALTER TABLE `enseignants`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `etudiants`
--
ALTER TABLE `etudiants`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `filieres`
--
ALTER TABLE `filieres`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `niveaux`
--
ALTER TABLE `niveaux`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `niveaux_filieres`
--
ALTER TABLE `niveaux_filieres`
  ADD PRIMARY KEY (`id_niveau`,`id_filiere`);

--
-- Index pour la table `salles`
--
ALTER TABLE `salles`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `seances`
--
ALTER TABLE `seances`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT pour les tables exportées
--

--
-- AUTO_INCREMENT pour la table `cours`
--
ALTER TABLE `cours`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=5;
--
-- AUTO_INCREMENT pour la table `enseignants`
--
ALTER TABLE `enseignants`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=6;
--
-- AUTO_INCREMENT pour la table `etudiants`
--
ALTER TABLE `etudiants`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=11;
--
-- AUTO_INCREMENT pour la table `filieres`
--
ALTER TABLE `filieres`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=6;
--
-- AUTO_INCREMENT pour la table `niveaux`
--
ALTER TABLE `niveaux`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=6;
--
-- AUTO_INCREMENT pour la table `salles`
--
ALTER TABLE `salles`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=11;
--
-- AUTO_INCREMENT pour la table `seances`
--
ALTER TABLE `seances`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=7;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
