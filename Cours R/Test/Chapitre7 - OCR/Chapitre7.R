load("Chapitre7.RData")

# Les vecteurs
vect_num = vector("numeric", 10)
vec_char = vector("character", 5)

# Générer des listes
suite_crois = 5:10
suite_dec = 10:5
repetition_num = rep(2, 10)
repetition_logic = rep(TRUE, 5)
sequence_pas = seq(2, 30, 5) # step = 5

# Concaténer
concat = c(suite_crois, suite_dec)

# Nommer éléments des vecteurs
nommer = 1:5
names(nommer) = c("a", "b", "c", "d", "e")

# Indexation
index = 1:15
# Indexation numérique
index6 = index[6]
index3_8 = index[3:8]
index3719 = index[c(3,7,1,9)]
index8888 = index[rep(8,4)] #répétition 4 foix du 8ème élément 
index10_15= index[-(1:9)]   #renvoie tous les éléments sauf les 9 premiers

# Indexation booléenne
index_bool = index[c(rep(TRUE,2), rep(FALSE,10), rep(TRUE,10))] # complète par des NA
index_sup7 = index[index > 7] # valeurs supérieures à 7

# Utiliser le nom des éléments
index_noms = 1:6
names(index_noms) = c("thib", "nico", "marou", "sab", "ben", "thib")
index_thib_marou = index_noms[c("thib", "marou")]         # prend seulement le premier "thib"
index_all_thib = index_noms[names(index_noms) == "thib"]  # prend tous les "thib"


## Opérations et analyses statistiques sur des vecteurs
poids <- c(85,78,54,98,66,78,77,62,89,92,76,77,55,68,71,72,99,102,54,66,98,75,82,83,75)
poids_plus1 = poids +1
#poids_moins1_cyclique = poids - c(1,0) # -1 sur 1 mesure sur 2, Warning car poids n'est pas un multiple de 2
poids_longueur = length(poids)
poids_start2 = head(poids,2)  # 2 premiers éléments de poids
poids_end3 = tail(poids,3)    # 3 derniers éléments de poids

# Trier
poids_sort_crois = sort(poids)
poids_sort_dec = sort(poids, decreasing = TRUE)
poids_order_crois = poids[order(poids)] # Utiliser order() pour ordonner 2 vecteurs dont les éléments
# sont liés pour avoir le même ordre entre eux
poids_order_dec = poids[order(poids, decreasing = TRUE)]
poids_rank = rank(poids)

## Analyser la distribution d'un vecteur
poids_moy = mean(poids)
poids_moy2 = sum(poids)/length(poids)
poids_med = median(poids, na.rm = T) # Si présence de valeur NA
poids_min = min(poids)
poids_max = max(poids)
poids_quartile = quantile(poids) # par défaut quartile() calcule les quartiles
poids_summary = summary(poids)
poids_variance = var(poids)
poids_ecart_type = sd(poids)

## Manipuler et comparer plusieurs vecteurs
noms1 = c("tib", "tib", "nico")
noms2 = c("marou", "sab", "tib")
nom12_union = union(noms1, noms2) # Renvoie l'ensemble l'univers de valeurs des deux vecteurs
nom12_intersect = intersect(noms1, noms2)
nom12_diff1 = setdiff(noms1, noms2) # setdiff() est asymétrique
nom12_diff2 = setdiff(noms2, noms1) # résultat différent

# Avec le jeu de données chargé (tailleG, tailleF, performanceG, performanceF)
# On utilise les names()
communG = intersect(names(performanceG), names(tailleG))
communF = intersect(names(performanceF), names(tailleF))
tailleG_in = names(tailleG) %in% names(performanceG) # renvoie un vecteur bool de la même taille que 
# tailleG. TRUE si nom présent dans performanceG
# FALSE sinon
# Ordonner les vecteurs de manière réciproque
tailleG2 = tailleG[communG]           # même vecteur communG
performanceG2 = performanceG[communG]
tailleF2 = tailleF[communF]           # même vecteur communG
performanceF2 = performanceF[communF]
# trier les deux vecteurs par rapport à la taille
tailleG2_tri = tailleG2[order(tailleG2)]  # même vecteur order(tailleG2)
performanceG2_tri = performanceG2[order(tailleG2)]

# Corrélation et régression linéaire
correlationG = cor(tailleG2_tri, performanceG2_tri)
reglineaireG = lm(performanceG2_tri ~ tailleG2_tri) # étude du comportement des
# performances par rapport à la taille des candidats
# Tests statistiques
correlation_test = cor.test(performanceG2_tri, tailleG2_tri) # Test de correlation
#wilcox_test = wilcox.test(performanceF2, performanceG2) # Test des médianes, test de Wilcozon-Mann-Whitney

## Les Facteurs
facteur = factor(c("A","B","A","B","C","B","D"))
levels(facteur) = c(levels(facteur), c("E","F"))
# names(), indexation sont idem aux vecteurs

# Du facteur au vecteur... et inversement
facteur_a_vecteur = as.vector(facteur)
vecteur = 1:5
vecteur_a_facteur = as.factor(vecteur)

## Les matrices
mat = matrix(nrow = 3, ncol = 5)
mat2_3 = mat[2,3]
Pierre <- c(8,9,15)
Nathalie <- c(17,12,13)
Jacques <- c(11,15,7)
Julie <- c(5,12,19)
matrice = matrix(c(Pierre, Nathalie, Jacques, Julie), nrow = 4, ncol = 3, byrow=T)
rownames(matrice) = c("Pierre", "Nathalie", "Jacques", "Julie")
colnames(matrice) = c("Histoire", "Biologie", "Sport")
matrice_pierre_Jacques = matrice[c("Pierre","Jacques"),1:2]
matrice_names = matrice[sort(rownames(matrice))[1:3], colnames(matrice)[c(1,3)]]
matrice_allLigne_histoire = matrice[,"Histoire"]

  #Statistiques sur matrice
matrice_moyenne_Nath = mean(matrice["Nathalie",])
matrice_moyenne = mean(matrice)

## Les dataframes
data_taille = c(185, 178, 165, 171, 172)
data_poids = c(82, 81, 55, 65, 68)
data_QI = c(110, 108, 125, 99, 124)
data_sexe = c("M","M","F","F","F")
dataframe = data.frame(dataframe_taille = data_taille, dataframe_poids = data_poids, dataframe_QI = data_QI, dataframe_sexe = data_sexe)
rownames(dataframe) = c("Paul", "Matthieu", "Camille", "Mireille", "Capucine")
dataframe_col_poids = dataframe$poids
#attach(dataframe) erreur non résolue